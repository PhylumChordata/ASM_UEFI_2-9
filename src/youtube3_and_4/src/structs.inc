; structs

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

struc EFI_SIMPLE_TEXT_INPUT_PROTOCOL
{
    .Reset                  void
    .ReadKeyStroke          void
    .WaitForKey             void
}
struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL

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
