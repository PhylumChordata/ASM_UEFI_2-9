@echo off
del *.efi
cls
@echo on

fasm bootx64.asm BOOTX64.EFI

pause