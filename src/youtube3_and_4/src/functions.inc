; Functions

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
        mov rcx, 0x8000000000000006   ; This means Not ready
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
