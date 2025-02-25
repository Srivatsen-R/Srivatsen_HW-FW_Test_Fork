/* Standard C includes -------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/
#include "stm32h7xx_hal.h"
#include "memoryMap.h"

/* Self include --------------------------------------------------------------*/
#include "bootloaderFunctions.h"
#include "flash.h"
#include "crc32.h"

#define MCU_OK 0

/* Type definiton ------------------------------------------------------------*/

/* External variables definiton ----------------------------------------------*/

/* Private constants ---------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
uint8_t flag_handler_str[512];
/* Private function prototypes -----------------------------------------------*/
typedef void (*pFunction)(void);

/* Private custom code -------------------------------------------------------*/

/*Function Definition*/
/**
 * @brief App Partition
*/
uint16_t getAppPartition(void)
{
	void *addr             = &__commondata_start__;
	const image_hdr_t *hdr;	
	hdr = (const image_hdr_t *)&__commondata_start__;

	if (hdr->image_magic != IMAGE_MAGIC)
	{
		// no valid image found
		return 0;
	}
	if (hdr->active_app == 1)
	{
		// verify app1 partition
		if (verifyApp1() == 1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if (hdr->active_app == 2)
	{
		// verify app2 partition
		if (verifyApp2() == 1)
		{
			return 2;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}

	return 0;
}


/**
 * @brief Verify CRC Of APP1
 *
 * @return uint8_t 0 = CRC Failed, 1 = CRC Verified
 */
uint8_t verifyApp1(void)
{
	void *addr1             = &__app1_start__;
	const image_hdr_t *hdr1 = (const image_hdr_t *)&__app1_start__;
	// uint16_t test = hdr->image_magic;
	if (hdr1->image_magic != IMAGE_MAGIC)
	{
		// Magic not equal, valid image not found
		return 0;
	}

	uint32_t len = hdr1->data_size;
	if (len == 0)
	{
		// Len == 0, invalid image, error in calculating image size
		return 0;
	}

	if (hdr1->active_app != 1)
	{
		// Invalid image at place of app1
		return 0;
	}

	uint32_t a = hdr1->crc;
	addr1 += APP_START_OFFSET;
	uint32_t b = crc32(addr1, len);
	if (a != b)
	{
		// CRC Failed
		return 0;
	}
	return 1;
}

/**
 * @brief Verify CRC of APP2
 *
 * @return uint8_t 0 = CRC Failed, 1 = CRC Verified
 */
uint8_t verifyApp2(void)
{
	void *addr2             = &__app2_start__;
	const image_hdr_t *hdr = (const image_hdr_t *)&__app2_start__;
	if (hdr->image_magic != IMAGE_MAGIC)
	{
		// Magic not equal, valid image not found
		return 0;
	}

	uint32_t len = hdr->data_size;
	if (len == 0)
	{
		// Len == 0, invalid image, error in calculating image size
		return 0;
	}

	if (hdr->active_app != 2)
	{
		// Invalid image at place of app2
		return 0;
	}

	uint32_t a = hdr->crc;
	addr2 += APP_START_OFFSET;
	uint32_t b = crc32(addr2, len);
	if (a != b)
	{
		// CRC Failed
		return 0;
	}
	return 1;
}


/* Function definition -------------------------------------------------------*/
/**
 * @brief Primary App Switch
 * 
 */
void switchToPrimaryApp(void)
{
	void *addr = &__app1_start__;
	addr += APP_START_OFFSET;
	const image_hdr_t *hdr = (const image_hdr_t *)&__app1_start__;
	uint32_t len           = hdr->data_size;
	uint32_t a             = hdr->crc;
	uint32_t b             = crc32(addr, len);
	if (a != b)
	{
		// CRC Failed
		return 0;
	}

	uint32_t JumpAddress = *(volatile uint32_t *)(APP1_VECTOR + 4);
	pFunction Jump       = (pFunction)JumpAddress;

	HAL_RCC_DeInit();
	HAL_DeInit();
	SCB_DisableDCache();
	SCB_DisableICache();

	SysTick->CTRL = 0;
	SysTick->LOAD = 0;
	SysTick->VAL  = 0;

	SCB->VTOR = APP1_VECTOR;

	__set_MSP(*(volatile uint32_t *)(APP1_VECTOR));
	Jump();
}

/* Function definition -------------------------------------------------------*/
/**
 * @brief Secondary App Switch
 * 
 */
void switchToSecondaryApp(void)
{
	void *addr = &__app2_start__;
	addr += APP_START_OFFSET;
	const image_hdr_t *hdr = (const image_hdr_t *)&__app2_start__;
	uint32_t len           = hdr->data_size;
	uint32_t a             = hdr->crc;
	uint32_t b             = crc32(addr, len);
	if (a != b)
	{
		// CRC Failed
		return 0;
	}

	uint32_t JumpAddress = *(volatile uint32_t *)(APP2_VECTOR + 4);
	pFunction Jump       = (pFunction)JumpAddress;

	HAL_RCC_DeInit();
	HAL_DeInit();
	SCB_DisableDCache();
	SCB_DisableICache();

	SysTick->CTRL = 0;
	SysTick->LOAD = 0;
	SysTick->VAL  = 0;

	SCB->VTOR = APP2_VECTOR;

	__set_MSP(*(volatile uint32_t *)(APP2_VECTOR));
	Jump();
}

/**
 * @brief Handle common bootloader flags
 *
 * @param flag
 * @return uint32_t
 */
void bootloader_flag_handler(uint32_t *flag)
{
	uint8_t boot_loop_count = ((*flag) >> 24) & 0xFF;
	if (((*flag) & BIT0) == 1 || boot_loop_count > BOOTLOOP_RETRY_COUNT)
	{
		// change active partition
		uint8_t current_partition = getAppPartition();
		if (current_partition == 1)
		{
			if (verifyApp2() == 1)
			{
				// valid app found at app2
				if (setApp2Active() == 0)
				{
					setApp1Active();
				}
				else
				{
					
				}
			}
			else
			{
				// app2 invalid
			}
		}
		else if (current_partition == 2)
		{
			if (verifyApp1() == 1)
			{
				// valid app found in app1
				if (setApp1Active() == 0)
				{
					setApp2Active();
				}
				else
				{
				}
			}
			else
			{

				// app1 invalid
			}
		}
		else
		{
			// no current partition
		}
		*flag = 0;
	}
}

/**
 * @brief Set the APP 1 as active app
 *
 * @return uint8_t 0 = pdFAIL, 1 = pdPASS
 */
uint8_t setApp1Active(void)
{
	uint32_t addr = &__commondata_start__;
	// Erase common area;
	if (Flash_Erase_Data(addr, 16) != MCU_OK)
	{
		return 0;
	}
	else
	{
		// data erase successful
	}

	const image_hdr_t *hdr = (const image_hdr_t *)&__app1_start__;
	const uint64_t *hdr_64 = (image_hdr_t *)hdr;
	int16_t hdr_size_64    = (sizeof(image_hdr_t) / 8) + 1;
	uint32_t loc           = &__commondata_start__;
	if (Flash_Write_Data(loc, hdr_64, hdr_size_64) != MCU_OK)
	{
		return 0;
	}
	else
	{
		// written successfully
	}

	return 1;
}

uint8_t setApp2Active(void)
{
	uint32_t addr = &__commondata_start__;
	// Erase common area
	if (Flash_Erase_Data(addr, 16) != MCU_OK)
	{
		return 0;
	}
	else
	{
		// data erase successful
	}

	const image_hdr_t *hdr = (const image_hdr_t *)&__app2_start__;
	const uint64_t *hdr_64 = (image_hdr_t *)hdr;
	int16_t hdr_size_64    = (sizeof(image_hdr_t) / 8) + 1;
	uint32_t loc           = &__commondata_start__;


	//8071501

	if (Flash_Write_Data(loc, hdr_64, hdr_size_64) != MCU_OK)
	{
		return 0;
	}
	else
	{
		// written successfully
	}

	return 1;
}

/* End of File ---------------------------------------------------------------*/