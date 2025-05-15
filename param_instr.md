# Taill des param de chaques instruction

#### Abel :
> sti : 0B, coding byte: 68, reg: 01, dir: 00 07, dir: 00 01, live: 01 params: 00 00 00 EA, ld: 02, coding byte: 90, dir: 00 00  00 00, reg: 03, zjmp: 09 indir: FF F4


#### Bill :
> sti: 0B, coding byte: 68, reg: 01, dir: 00 18, dir: 00 01,
> fork: 0C, indir: 00 16,
> ld: 02, coding byte : 90, dir : 00 00 00 64, reg 04;
> ld: 02, coding byte : 90, dir : 00 00 00 02, reg 05;
> live: 01, dir : 00 00 00 01;
> sti: 0B, coding byte : 54, reg: 05, reg: 04, reg: 01;
> add: 04, coding byre: 54, reg: 04, reg: 05, reg: 04;
> ld: 02, coding byte: 90, dir: 00 00 00 00, reg: 08;
> zjmp: 09, reg: FF EA;

#### Tyron :
>  sti: 0B, coding byte: 68, reg: 01, dir: 00 07, dir: 00 01;
> live: 01, dir: 00 00 00 7B;
> ld: 02, coding byte: 90, dir: 00 00 00 00, reg: 03;
> zjmp: 09, dir: FF F4

#### PDD :
> sti: 0B, coding byte: 68, reg: 01, dir: 00 35, dir: 00 01;
> fork: 0C, dir: 00 2E;
> ld: 02, coding byte: 90, dir: 00 00 00 4C, reg: 01;
> ld: 02, coding byte: 90, dir: 00 00 00 28, reg: 06;
> ld: 02, coding byte: 90, dir: 00 00 00 01, reg: 07;
> ld: 02, coding byte: 90, dir: 00 00 00 0F, reg: 04;
> ld: 02, coding byte: 90, dir: 00 00 00 0F, reg: 05;
> sub: 05, coding byte: 54, reg: 04, reg: 05, reg: 03

# Taille des indir, dir et reg en fonction des instructions :
- sti : reg = 1, dir = 2;
- ld : reg = 1, dir = 4;
- zjmp : indir = 2, dir= 2;
- live : dir = 4;
- fork : dir = 2;
- add: reg = 1;


# Conclusion :

- PC n'est pas un register. Il est stocker à côter.
- Dir est à 4, Indir est à 2. Mais index est à 2. Certaines instruction on des index comme argument, c'est préciser sur le pdf.
- Carry est stocker en dehor.
- Il y a 16 register de 1 à 16; un register est coder sur 1 byte mais peux stocker jusqu'à 4 bytes (un int).



test 4 bytes to int :
```c
int main(void)
{
    uint8_t byte1 = 0x0D;
    uint8_t byte2 = 0x1F;
    uint8_t byte3 = 0xC6;
    uint8_t byte4 = 0x8F;
    // uint8_t byte1 = 0x00;
    // uint8_t byte2 = 0x00;
    // uint8_t byte3 = 0x00;
    // uint8_t byte4 = 0x0F;
    int result = 0;

    result = byte_to_int(byte1, byte2, byte3, byte4);
    printf("Result = %d\n", result);
    printf("in binary :\n00001101000111111100011010001111\n");
    printf(INT_TO_BINARY_PATTERN"\n", INT_TO_BINARY(result));
    printf("Byte 1: "BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(byte1));
    printf("Byte 2: "BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(byte2));
    printf("Byte 3: "BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(byte3));
    printf("Byte 4: "BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(byte4));
    // printf("Byte = "INT_TO_BINARY_PATTERN" ; Byte1 = "INT_TO_BINARY_PATTERN"\n", INT_TO_BINARY(byte), INT_TO_BINARY(byte1));
    return 0;
}
```

//add array de boolean pour live
//fix select champion pour ne pas animer champion mort
// ajouter un bouleen a champion_t pour la mort definitive ?