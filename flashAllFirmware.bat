:: Deletes All files in the Current Directory With Prompts and Warnings 
::(Hidden, System, and Read-Only Files are Not Affected) 
:: 
@ECHO OFF 
openocd.exe -f ./openocd.cfg -c "program build/Pegasus3.1v-appPrimary.bin exit 0x8080000"
openocd.exe -f ./openocd.cfg -c "program build/Pegasus3.1v-appSecondary.bin exit 0x8019000"