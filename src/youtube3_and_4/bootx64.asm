; UEFI Written in FASM ( Flat Assembler )
; https://github.com/ThatOSDev
; fasm bootx64.asm BOOTX64.EFI

format pe64 dll efi
entry efimain

section '.text' code executable readable

include 'src/consts.inc'
include 'src/structs.inc'
include 'src/functions.inc'

efimain:
    INITIALIZE_EFI
    TEXTOUTRESET
    COLOR EFI_YELLOW
    PRINT[welcome]
    COLOR EFI_GREEN
    PRINT[hitkey]
    WAITKEY
    TEXTOUTRESET
    COLOR EFI_LIGHTMAGENTA
    PRINT[leaving]
    COLOR EFI_GREEN
    PRINT[hitkey]
    WAITKEY
    PRINT[exiting]
   
    QUIT

section '.reloc' fixups data discardable

section '.data' code readable writeable

ImageHandle   dq ?
SystemTable   dq ?
Key           dq ?
welcome       du "Welcome to the new UEFI FASM Test.", 13, 10, 0, 0
leaving       du "Time to leave", 13, 10, 13, 10, 0, 0
hitkey        du "Hit any Key", 13, 10, 0, 0
exiting       du "Exiting....", 13, 10, 0, 0


