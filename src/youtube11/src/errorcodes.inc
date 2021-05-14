; Error Codes

macro RESULTS 0
{
    push r15
    mov r15, 0

    COLOR EFI_LIGHTCYAN
    lea rcx, [SUCCESS]
    mov rax, EFI_SUCCESS
    cmp r15, rax
    je @f
    
    COLOR EFI_LIGHTRED

    lea rcx, [LOAD_ERROR]
    mov rax, EFI_LOAD_ERROR
    cmp r15, rax
    je @f
    
    lea rcx, [INVALID_PARAMETER]
    mov rax, EFI_INVALID_PARAMETER
    cmp r15, rax
    je @f

    lea rcx, [UNSUPPORTED]
    mov rax, EFI_UNSUPPORTED
    cmp r15, rax
    je @f

    lea rcx, [BAD_BUFFER_SIZE]
    mov rax, EFI_BAD_BUFFER_SIZE
    cmp r15, rax
    je @f

    lea rcx, [BUFFER_TOO_SMALL]
    mov rax, EFI_BUFFER_TOO_SMALL
    cmp r15, rax
    je @f
    
    lea rcx, [NOT_READY]
    mov rax, EFI_NOT_READY
    cmp r15, rax
    je @f

    lea rcx, [DEVICE_ERROR]
    mov rax, EFI_DEVICE_ERROR
    cmp r15, rax
    je @f
    
    lea rcx, [WRITE_PROTECTED]
    mov rax, EFI_WRITE_PROTECTED
    cmp r15, rax
    je @f
    
    lea rcx, [OUT_OF_RESOURCES]
    mov rax, EFI_OUT_OF_RESOURCES
    cmp r15, rax
    je @f
    
    lea rcx, [VOLUME_CORRUPTED]
    mov rax, EFI_VOLUME_CORRUPTED
    cmp r15, rax
    je @f
    
    lea rcx, [VOLUME_FULL]
    mov rax, EFI_VOLUME_FULL
    cmp r15, rax
    je @f
    
    lea rcx, [NO_MEDIA]
    mov rax, EFI_NO_MEDIA
    cmp r15, rax
    je @f
    
    lea rcx, [MEDIA_CHANGED]
    mov rax, EFI_MEDIA_CHANGED
    cmp r15, rax
    je @f

    lea rcx, [NOT_FOUND]
    mov rax, EFI_NOT_FOUND
    cmp r15, rax
    je @f

    lea rcx, [ACCESS_DENIED]
    mov rax, EFI_ACCESS_DENIED
    cmp r15, rax
    je @f

    lea rcx, [NO_RESPONSE]
    mov rax, EFI_NO_RESPONSE
    cmp r15, rax
    je @f

    lea rcx, [NO_MAPPING]
    mov rax, EFI_NO_MAPPING
    cmp r15, rax
    je @f

    lea rcx, [TIMEOUT]
    mov rax, EFI_TIMEOUT
    cmp r15, rax
    je @f

    lea rcx, [NOT_STARTED]
    mov rax, EFI_NOT_STARTED
    cmp r15, rax
    je @f

    lea rcx, [ALREADY_STARTED]
    mov rax, EFI_ALREADY_STARTED
    cmp r15, rax
    je @f

    lea rcx, [ABORTED]
    mov rax, EFI_ABORTED
    cmp r15, rax
    je @f

    lea rcx, [ICMP_ERROR]
    mov rax, EFI_ICMP_ERROR
    cmp r15, rax
    je @f

    lea rcx, [TFTP_ERROR]
    mov rax, EFI_TFTP_ERROR
    cmp r15, rax
    je @f

    lea rcx, [PROTOCOL_ERROR]
    mov rax, EFI_PROTOCOL_ERROR
    cmp r15, rax
    je @f

    lea rcx, [INCOMPATIBLE_VERSION]
    mov rax, EFI_INCOMPATIBLE_VERSION
    cmp r15, rax
    je @f

    lea rcx, [SECURITY_VIOLATION]
    mov rax, EFI_SECURITY_VIOLATION
    cmp r15, rax
    je @f

    lea rcx, [CRC_ERROR]
    mov rax, EFI_CRC_ERROR
    cmp r15, rax
    je @f

    lea rcx, [END_OF_MEDIA]
    mov rax, EFI_END_OF_MEDIA
    cmp r15, rax
    je @f

    lea rcx, [END_OF_FILE]
    mov rax, EFI_END_OF_FILE
    cmp r15, rax
    je @f

    lea rcx, [INVALID_LANGUAGE]
    mov rax, EFI_INVALID_LANGUAGE
    cmp r15, rax
    je @f

    lea rcx, [COMPROMISED_DATA]
    mov rax, EFI_COMPROMISED_DATA
    cmp r15, rax
    je @f

    lea rcx, [IP_ADDRESS_CONFLICT]
    mov rax, EFI_IP_ADDRESS_CONFLICT
    cmp r15, rax
    je @f

    lea rcx, [HTTP_ERROR]
    mov rax, EFI_HTTP_ERROR
    cmp r15, rax
    je @f

    COLOR EFI_RED
    PRINT[UNKNOWN_ERROR]
    jmp $

    @@:
    PRINT [rcx]
    pop r15
}

