; structs

struc UINT8
{
    . db ?
}

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

struc EFI_BOOT_SERVICES
{
    .Hdr                                    EFI_TABLE_HEADER                  
    .RaiseTPL                               void  ; EFI_RAISE_TPL                     
    .RestoreTPL                             void  ; EFI_RESTORE_TPL                   
    .AllocatePages                          void  ; EFI_ALLOCATE_PAGES                
    .FreePages                              void  ; EFI_FREE_PAGES                    
    .GetMemoryMap                           void  ; EFI_GET_MEMORY_MAP                
    .AllocatePool                           void  ; EFI_ALLOCATE_POOL                 
    .FreePool                               void  ; EFI_FREE_POOL                     
    .CreateEvent                            void  ; EFI_CREATE_EVENT                  
    .SetTimer                               void  ; EFI_SET_TIMER                     
    .WaitForEvent                           void  ; EFI_WAIT_FOR_EVENT                
    .SignalEvent                            void  ; EFI_SIGNAL_EVENT                  
    .CloseEvent                             void  ; EFI_CLOSE_EVENT                   
    .CheckEvent                             void  ; EFI_CHECK_EVENT                   
    .InstallProtocolInterface               void  ; EFI_INSTALL_PROTOCOL_INTERFACE    
    .ReinstallProtocolInterface             void  ; EFI_REINSTALL_PROTOCOL_INTERFACE  
    .UninstallProtocolInterface             void  ; EFI_UNINSTALL_PROTOCOL_INTERFACE  
    .HandleProtocol                         void  ; EFI_HANDLE_PROTOCOL               
    .Reserved                               void
    .RegisterProtocolNotify                 void  ; EFI_REGISTER_PROTOCOL_NOTIFY               
    .LocateHandle                           void  ; EFI_LOCATE_HANDLE                          
    .LocateDevicePath                       void  ; EFI_LOCATE_DEVICE_PATH                     
    .InstallConfigurationTable              void  ; EFI_INSTALL_CONFIGURATION_TABLE            
    .LoadImage                              void  ; EFI_IMAGE_LOAD                             
    .StartImage                             void  ; EFI_IMAGE_START                            
    .Exit                                   void  ; EFI_EXIT                                   
    .UnloadImage                            void  ; EFI_IMAGE_UNLOAD                           
    .ExitBootServices                       void  ; EFI_EXIT_BOOT_SERVICES                     
    .GetNextMonotonicCount                  void  ; EFI_GET_NEXT_MONOTONIC_COUNT               
    .Stall                                  void  ; EFI_STALL                                  
    .SetWatchdogTimer                       void  ; EFI_SET_WATCHDOG_TIMER                     
    .ConnectController                      void  ; EFI_CONNECT_CONTROLLER                     
    .DisconnectController                   void  ; EFI_DISCONNECT_CONTROLLER                  
    .OpenProtocol                           void  ; EFI_OPEN_PROTOCOL                          
    .CloseProtocol                          void  ; EFI_CLOSE_PROTOCOL                         
    .OpenProtocolInformation                void  ; EFI_OPEN_PROTOCOL_INFORMATION              
    .ProtocolsPerHandle                     void  ; EFI_PROTOCOLS_PER_HANDLE                   
    .LocateHandleBuffer                     void  ; EFI_LOCATE_HANDLE_BUFFER                   
    .LocateProtocol                         void  ; EFI_LOCATE_PROTOCOL                        
    .InstallMultipleProtocolInterfaces      void  ; EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES   
    .UninstallMultipleProtocolInterfaces    void  ; EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES 
    .CalculateCrc32                         void  ; EFI_CALCULATE_CRC32                        
    .CopyMem                                void  ; EFI_COPY_MEM                               
    .SetMem                                 void  ; EFI_SET_MEM                                
    .CreateEventEx                          void  ; EFI_CREATE_EVENT_EX                        
}
struct EFI_BOOT_SERVICES

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

; Graphics
struc EFI_GRAPHICS_OUTPUT_BLT_PIXEL
{
    .Blue                   UINT8
    .Green                  UINT8
    .Red                    UINT8
    .Reserved               UINT8
}
struct EFI_GRAPHICS_OUTPUT_BLT_PIXEL

struc EFI_PIXEL_BITMASK
{
    .RedMask                UINT32    
    .GreenMask              UINT32    
    .BlueMask               UINT32    
    .ReservedMask           UINT32    
}
struct EFI_PIXEL_BITMASK

struc EFI_GRAPHICS_OUTPUT_MODE_INFORMATION
{
    .Version                UINT32
    .HorizontalResolution   UINT32
    .VerticalResolution     UINT32
    .PixelFormat            UINT32
    .PixelInformation       EFI_PIXEL_BITMASK        
    .PixelsPerScanLine      UINT32
}
struct EFI_GRAPHICS_OUTPUT_MODE_INFORMATION

struc EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE
{
    .MaxMode                UINT32
    .Mode                   UINT32
    .Info                   EFI_GRAPHICS_OUTPUT_MODE_INFORMATION
    .SizeOfInfo             void
    .FrameBufferBase        void
    .FrameBufferSize        void
}
struct EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE

struc EFI_GRAPHICS_OUTPUT_PROTOCOL
{
    .QueryMode              void
    .SetMode                void
    .Blt                    void
    .Mode                   EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE        
}
struct EFI_GRAPHICS_OUTPUT_PROTOCOL

