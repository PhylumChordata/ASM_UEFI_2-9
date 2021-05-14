; Functions

; UEFI 2.8b Specs PDF Page 29 & 30
; The integer values are passed from left to right in Rcx, Rdx, R8, and R9 registers.
; Rax is a return register

macro INITIALIZE_EFI
{
    push rsi
    sub rsp, 8 * 8   ; 8 times 8 bits = 64
    mov [ImageHandle], rcx
    mov [SystemTable], rdx
}

macro COLOR 0
{
    mov rdx, 0
    mov rcx, [SystemTable]
    mov rcx, [rcx + EFI_SYSTEM_TABLE.ConOut]
    call [rcx + EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL.SetAttribute]
}

macro PRINT 0
{
    lea rdx, 0
    mov rcx, [SystemTable]
    mov rcx, [rcx + EFI_SYSTEM_TABLE.ConOut]
    call [rcx + EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL.OutputString]
}

macro TEXTOUTRESET
{
    mov rdx, 1
    mov rcx, [SystemTable]
    mov rcx, [rcx + EFI_SYSTEM_TABLE.ConOut]
    call [rcx + EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL.Reset]
}

macro WAITKEY
{
    mov rdx, 1
    mov rcx, [SystemTable]
    mov rcx, [rcx + EFI_SYSTEM_TABLE.ConIn]
    call [rcx + EFI_SIMPLE_TEXT_INPUT_PROTOCOL.Reset]

    @@:
	    lea rdx, [Key]
        mov rcx, [SystemTable]
        mov rcx, [rcx + EFI_SYSTEM_TABLE.ConIn]
        call [rcx + EFI_SIMPLE_TEXT_INPUT_PROTOCOL.ReadKeyStroke]
        mov rcx, EFI_NOT_READY
        cmp rax, rcx
        je @b
}

macro QUIT
{
    add rsp, 8 * 8   ; 8 times 8 bits = 64
    pop rsi
	xor rax, rax  ; EFI_SUCCESS = 0x0
	retn

    jmp $ ; This is here as a guard
}

macro COLDREBOOT       ; Resets whole computer
{
    mov rcx, 0                           ; 0 = EfiResetCold
    mov rdx, EFI_SUCCESS
    mov r8, 0
    mov r9, [SystemTable]
    mov r9, [r9 + EFI_SYSTEM_TABLE.RuntimeServices]
    call [r9 + EFI_RUNTIME_SERVICES.ResetSystem]

    jmp $ ; This is here as a guard
}

macro WARMREBOOT       ; Resets CPU and Re-Initializes system   ( NOTE: Not all computers support this )
{
    mov rcx, 1                           ; 1 = EfiResetWarm
    mov rdx, EFI_SUCCESS
    mov r8, 0
    mov r9, [SystemTable]
    mov r9, [r9 + EFI_SYSTEM_TABLE.RuntimeServices]
    call [r9 + EFI_RUNTIME_SERVICES.ResetSystem]

    jmp $ ; This is here as a guard
}

macro SHUTDOWN
{
    mov rcx, 2                           ; 2 = EfiResetShutdown
    mov rdx, EFI_SUCCESS
    mov r8, 0
    mov r9, [SystemTable]
    mov r9, [r9 + EFI_SYSTEM_TABLE.RuntimeServices]
    call [r9 + EFI_RUNTIME_SERVICES.ResetSystem]

    jmp $ ; This is here as a guard
}

macro SETCOLOR %0
{
    mov rax, %0
    mov [CurrentColor], rax
}

macro DRAWPIXEL %0, %1
{
    push rsi
    push rsp

    mov rcx, [GOP_Handle]      ; EFI_GRAPHICS_OUTPUT_PROTOCOL
    mov rdx, [CurrentColor]
    mov r8, 0                  ; EfiBltVideoFill   <---------------  EFI_GRAPHICS_OUTPUT_BLT_OPERATION
    mov r9, 0                  ; source X
    mov qword[rsp + 8*4], 0    ; source Y          <---------------  This begins our shadow stack
    mov qword[rsp + 8*5], %0   ; destination X
    mov qword[rsp + 8*6], %1   ; destination Y
    mov qword[rsp + 8*7], 1   ; width
    mov qword[rsp + 8*8], 1   ; height
    mov qword[rsp + 8*9], 0    ; delta
    call [rcx + EFI_GRAPHICS_OUTPUT_PROTOCOL.Blt]

    pop rsp
    pop rsi
}

macro DRAWSQUARE %0, %1, %2, %3
{
    push rsi
    push rsp

    mov rcx, [GOP_Handle]      ; EFI_GRAPHICS_OUTPUT_PROTOCOL
    mov rdx, [CurrentColor]
    mov r8, 0                  ; EfiBltVideoFill   <---------------  EFI_GRAPHICS_OUTPUT_BLT_OPERATION
    mov r9, 0                  ; source X
    mov qword[rsp + 8*4], 0    ; source Y          <---------------  This begins our shadow stack
    mov qword[rsp + 8*5], %0   ; destination X
    mov qword[rsp + 8*6], %1   ; destination Y
    mov qword[rsp + 8*7], %2   ; width
    mov qword[rsp + 8*8], %3   ; height
    mov qword[rsp + 8*9], 0    ; delta
    call [rcx + EFI_GRAPHICS_OUTPUT_PROTOCOL.Blt]

    pop rsp
    pop rsi
}

macro ENABLEGOP
{
    COLOR EFI_CYAN
    PRINT[loadinggop]
    
    mov rcx, EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID
    mov rdx, 0
    lea r8, [GOP_Handle]
    mov r9, [SystemTable]
    mov r9, [r9 + EFI_SYSTEM_TABLE.BootServices]
    call [r9 + EFI_BOOT_SERVICES.LocateProtocol]
    RESULTS rax
}