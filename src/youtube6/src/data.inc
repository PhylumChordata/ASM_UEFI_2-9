; data

EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID    db 0xde, 0xa9, 0x42, 0x90, 0xdc, 0x23, 0x38, 0x4a, 0x96, 0xfb, 0x7a, 0xde, 0xd0, 0x80, 0x51, 0x6a
                                  
ImageHandle           dq    ?
SystemTable           dq    ?
Key                   dq    ?
GOP_Handle            dq    EFI_GRAPHICS_OUTPUT_PROTOCOL
CurrentColor          dq    ?

GOP_COLOR_ORANGE          dq 0xffffa500
GOP_COLOR_CYAN            dq 0xff00ffff
GOP_COLOR_RED             dq 0xffff0000
GOP_COLOR_GREEN           dq 0xff00ff00
GOP_COLOR_BLUE            dq 0xff0000ff
GOP_COLOR_GRAY            dq 0xff888888
GOP_COLOR_WHITE           dq 0xffffffff
GOP_COLOR_BLACK           dq 0xff000000

welcome               du "Welcome to the new UEFI FASM Test.", 13, 10, 0, 0
leaving               du "Time to leave", 13, 10, 13, 10, 0, 0
hitkey                du "Hit any Key", 13, 10, 0, 0
exiting               du "Exiting....", 13, 10, 0, 0
loadinggop            du "Loading GOP ... ", 0, 0

SUCCESS               du "EFI_SUCCESS", 13, 10, 0, 0
UNKNOWN_ERROR         du "Unknown EFI_ERROR. Program Halted.", 13, 10, 13, 10, 0, 0
LOAD_ERROR            du "EFI_LOAD_ERROR", 13, 10, 0, 0
INVALID_PARAMETER     du "EFI_INVALID_PARAMETER", 13, 10, 0, 0
UNSUPPORTED           du "EFI_UNSUPPORTED", 13, 10, 0, 0
BAD_BUFFER_SIZE       du "EFI_BAD_BUFFER_SIZE", 13, 10, 0, 0
BUFFER_TOO_SMALL      du "EFI_BUFFER_TOO_SMALL", 13, 10, 0, 0
NOT_READY             du "EFI_NOT_READY", 13, 10, 0, 0
DEVICE_ERROR          du "EFI_DEVICE_ERROR", 13, 10, 0, 0
WRITE_PROTECTED       du "EFI_WRITE_PROTECTED", 13, 10, 0, 0
OUT_OF_RESOURCES      du "EFI_OUT_OF_RESOURCES", 13, 10, 0, 0
VOLUME_CORRUPTED      du "EFI_VOLUME_CORRUPTED", 13, 10, 0, 0
VOLUME_FULL           du "EFI_VOLUME_FULL", 13, 10, 0, 0
NO_MEDIA              du "EFI_NO_MEDIA", 13, 10, 0, 0
MEDIA_CHANGED         du "EFI_MEDIA_CHANGED", 13, 10, 0, 0
NOT_FOUND             du "EFI_NOT_FOUND", 13, 10, 0, 0
ACCESS_DENIED         du "EFI_ACCESS_DENIED", 13, 10, 0, 0
NO_RESPONSE           du "EFI_NO_RESPONSE", 13, 10, 0, 0
NO_MAPPING            du "EFI_NO_MAPPING", 13, 10, 0, 0
TIMEOUT               du "EFI_TIMEOUT", 13, 10, 0, 0
NOT_STARTED           du "EFI_NOT_STARTED", 13, 10, 0, 0
ALREADY_STARTED       du "EFI_ALREADY_STARTED", 13, 10, 0, 0
ABORTED               du "EFI_ABORTED", 13, 10, 0, 0
ICMP_ERROR            du "EFI_ICMP_ERROR", 13, 10, 0, 0
TFTP_ERROR            du "EFI_TFTP_ERROR", 13, 10, 0, 0
PROTOCOL_ERROR        du "EFI_PROTOCOL_ERROR", 13, 10, 0, 0
INCOMPATIBLE_VERSION  du "EFI_INCOMPATIBLE_VERSION", 13, 10, 0, 0
SECURITY_VIOLATION    du "EFI_SECURITY_VIOLATION", 13, 10, 0, 0
CRC_ERROR             du "EFI_CRC_ERROR", 13, 10, 0, 0
END_OF_MEDIA          du "EFI_END_OF_MEDIA", 13, 10, 0, 0
END_OF_FILE           du "EFI_END_OF_FILE", 13, 10, 0, 0
INVALID_LANGUAGE      du "EFI_INVALID_LANGUAGE", 13, 10, 0, 0
COMPROMISED_DATA      du "EFI_COMPROMISED_DATA", 13, 10, 0, 0
IP_ADDRESS_CONFLICT   du "EFI_IP_ADDRESS_CONFLICT", 13, 10, 0, 0
HTTP_ERROR            du "EFI_HTTP_ERROR", 13, 10, 0, 0
