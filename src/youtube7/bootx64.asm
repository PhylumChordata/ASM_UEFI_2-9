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

    ENABLEGOP

    WAITKEY
    
    SETCOLOR GOP_COLOR_ORANGE
    
    DRAWSQUARE 50, 50, 112, 400
    
    SETCOLOR GOP_COLOR_GREEN
    
    DRAWSQUARE 60, 100, 30, 200

    COLOR EFI_GREEN
    PRINT[hitkey]
    WAITKEY
    COLOR EFI_LIGHTMAGENTA
    PRINT[leaving]
   ; QUIT
    COLDREBOOT

section '.reloc' fixups data discardable

section '.data' code readable writeable

include 'src/data.inc'
