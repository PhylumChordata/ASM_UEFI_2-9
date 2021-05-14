; UEFI Written in FASM
; https://github.com/ThatOSDev
; fasm bootx64.asm BOOTX64.EFI

struc UINT32
{
    align 4
    . dd ?
}

struc void
{
    align 8
    . dq ?
}

macro struct name
{
    virtual at 0
      name name
    end virtual
}

struc EFI_TABLE_HEADER
{
    .Signature              void
    .Revision               UINT32
    .HeaderSize             UINT32
    .CRC32                  UINT32
    .Reserved               UINT32
}
struct EFI_TABLE_HEADER

struc EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL
{
    .Reset                  void
    .OutputString           void
    .TestString             void
    .QueryMode              void
    .SetMode                void
    .SetAttribute           void
    .ClearScreen            void
    .SetCursorPosition      void
    .EnableCursor           void
    .Mode                   void
}
struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL

struc EFI_SYSTEM_TABLE
{
    .Hdr                    EFI_TABLE_HEADER
    .FirmwareVendor         void
    .FirmwareRevision       UINT32
    .ConsoleInHandle        void
    .ConIn                  void
    .ConsoleOutHandle       void
    .ConOut                 void
    .StandardErrorHandle    void
    .StdErr                 void
    .RuntimeServices        void
    .BootServices           void
    .NumberOfTableEntries   void
    .ConfigurationTable     void
}
struct EFI_SYSTEM_TABLE

format pe64 dll efi
entry efimain

section '.text' code executable readable

efimain:
    mov [ImageHandle], rcx
    mov [SystemTable], rdx

    mov rdx, 1
    mov rcx, [SystemTable]
    mov rcx, [rcx + EFI_SYSTEM_TABLE.ConOut]
    call [rcx + EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL.Reset]

    mov rdx, 0x0E             ; EFI_YELLOW
    mov rcx, [SystemTable]
    mov rcx, [rcx + EFI_SYSTEM_TABLE.ConOut]
    call [rcx + EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL.SetAttribute]
    
    lea rdx, [welcome]
    mov rcx, [SystemTable]
    mov rcx, [rcx + EFI_SYSTEM_TABLE.ConOut]
    call [rcx + EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL.OutputString]

    jmp $

section '.reloc' fixups data discardable

section '.data' code readable writeable

ImageHandle   dq ?
SystemTable   dq ?
welcome       du "We Have Text", 13, 10, 0, 0
