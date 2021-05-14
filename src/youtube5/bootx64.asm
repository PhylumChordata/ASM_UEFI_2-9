; UEFI Written in FASM ( Flat Assembler )
; https://github.com/ThatOSDev
; fasm bootx64.asm BOOTX64.EFI

format pe64 dll efi
entry efimain

include 'src/consts.inc'
include 'src/structs.inc'

section '.text' code executable readable

include 'src/errorcodes.inc'
include 'src/functions.inc'

efimain:
    INITIALIZE_EFI
    TEXTOUTRESET
    COLOR EFI_YELLOW
    PRINT[welcome]
    
    COLOR EFI_CYAN
    PRINT[RANDOM_TEST]
    mov rax, EFI_HTTP_ERROR
    RESULTS rax
    
    COLOR EFI_GREEN
    PRINT[hitkey]
    WAITKEY
    COLOR EFI_LIGHTMAGENTA
    PRINT[leaving]
    QUIT

section '.reloc' fixups data discardable

section '.data' code readable writeable

RANDOM_TEST       du "Checking random test ... ", 0, 0

include 'src/data.inc'
