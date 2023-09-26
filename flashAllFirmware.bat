:: Deletes All files in the Current Directory With Prompts and Warnings 
::(Hidden, System, and Read-Only Files are Not Affected) 
:: 
@ECHO OFF 
@REM python patch_image_header.py Build/Pegasus3.1v-appPrimary.bin
@REM python patch_image_header.py Build/Pegasus3.1v-appSecondary.bin

openocd.exe -f ./openocd.cfg -c "program build/Pegasus3.1v-bootloader.bin exit 0x8000000"
openocd.exe -f ./openocd.cfg -c "program build/Pegasus3.1v-appPrimary.bin exit 0x8040000"
openocd.exe -f ./openocd.cfg -c "program build/Pegasus3.1v-appSecondary.bin exit 0x8080000"