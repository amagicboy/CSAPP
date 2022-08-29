#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limit.h>

/*
    263 265 266 268 270 271 273

    位运算判断两个数大小
*/

int HA_261(int x)
{
    int INT_BITS=(sizeof(int)<<3);
    int ans1=!(x^(((1<<INT_BITS)-1)));
    int ans2=!(x^0);
    int ans3=!((x&0xFF)^0xFF);
    int ans4=!(((x&(0xFF<<(INT_BITS-8)))^(0xFF<<(INT_BITS-8))));
    return ans1|ans2|ans3|ans4;
}

int HA_262()
{
    int INT_BITS=sizeof(int)<<3;
    int UINT_MAX=(1<<INT_BITS)-1;
    int x=0x01<<(INT_BITS-1); 
    x=x>>(INT_BITS-1);
    return !(x^UINT_MAX);
}

unsigned HA_263_srl(unsigned x, int k)//QE1
{
    int INT_BITS=sizeof(int)<<3;
    unsigned xsra=(int)x>>k;
    
    return xsra&(INT_BITS-k);
}

int HA_263_sra(int x, int k)//QE2
{
    int xsrl=(unsigned)x>>k;
    int sign=(x>>31)&0x01;
    unsigned mask=-sign<<w-k;

    return xsrl|mask;
}

int HA_264_any_odd_one(unsigned x)
{
    int INT_BITS=sizeof(int)<<3;
    int tmp=x&(0xAAAAAAAA);
    return !(tmp^0xAAAAAAAA);
}

int HA_265_odd_ones(unsigned x)//QE3
{
    x^=x>>16;
    x^=x>>8;
    x^=x>>4;
    x^=x>>2;
    x^=x>>1;

    return x&0x1;
}

int HA_266_leftmost_one(unsigned x)//QE4
{
    x|=x>>16;
    x|=x>>8;
    x|=x>>4;
    x|=x>>2;
    x|=x>>1;
    return x-(x>>1);
}

int HA_267_bad_int_size_is_32()
{
    /*  32
    int set_msb=1<<31;
    int beyond_msb=0xFFFFFFFF+1;*/
    
    /* 16 */
    int set_msb=1<<15;
    int beyond_msb=0xFFFF+1;
    
    return set_msb&&!beyond_msb;
}

int HA_268_lower_onr_mask(int n)//QE5
{
    // error: n=32
    return -0u>>((sizeof(int<<3))-n);
}

unsigned HA_269_rotate_left(unsigned x, int n)
{

    unsigned tmp=(x>>(32-n))&(0xFFFFFFFF);
    return (x<<n)|tmp;
}

int HA_270_fits_bits(int x, int n)//QE6
{
    int w=sizeof(int)<<3;
    unsigned mask=INT_MIN>>(w-n);
    unsigned sign=x>>w-1&mask;
    return x==(x&~mask|sign);
}

int HA_271_xbyte(unsigned word, int bytenum)
{
    return (word>>(bytenum<<3))&0xff;
}

void HA_272_copy_int(int val, void *buf, size_t maxbytes)
{
    if(maxbytes-sizeof(val)>=0)
        memcpy(buf, (void *)&val, sizeof(val));
}

int HA_273_saturating_add(int x,int y)//QE7
{
#define UX ((unsigned)x)
#define UY ((unsigned)y)
    int w=sizeof(int)<<3;
    unsigned sign_of_x=ux>>w-1, sign_of_y=UY>>w-1;
    unsigned sum=UX+UY, sign_of_sum=sum>>w-1;
#define SX sign_of_x
#define SY sign_of_y
#define SS sign_of_sum
    unsigned overflow=-(SX^SS && SY^SS);
    unsigned positive_overflow=-(!SX&&!SY&&SS);
    unsigned negative_overlfow=-(SX&&SY&&!SS);
#define O overflow
#define PO positive_overflow
#define NO negative_overlfow
    return (~0&sum)|(PO&INT_MAX)|(NO&INT_MIN);
#undef NO
#undef PO
#undef O
#undef SS
#undef SY
#undef SX
#undef UY
#undef UX
}

int HA_274_tsub_ok(int x, int y)
{
    int sum=x-y;
    if(x>0&&y<0&&sum<=0)return -1;
    else if(x<0&&y>0&&sum>=0)return -1;
    return 1;
}

int HA_275_signed_high_prod(int x, int y)
{
    int INT_BITS=sizeof(int)<<3;
    return (x*y)>>INT_BITS;
}

unsigned HA_275_unsigned_high_prod(unsigned x, unsigned y)
{
    return (unsigned)HA_275_signed_high_prod(x, y);
}

void* HA_276_calloc(size_t nmemb, size_t size)
{
    /*if(nmemb==0||size==0)return NULL;
    void * dst;
    for(size_t i=0; i<nmemb; i++)
    {
        dst=malloc(size);
        memcpy(dst, 0, size);
    }*/
}

void HA_277_multiK(int x, int k)
{
    //k==17  x<<4+x
    //k==-7  x>>3+x
    //k==60  (x<<6)-(x<<2)
    //k==-112 (x>>127)+(x<<2)+x
}

int HA_278_divide_power(int x, int k)
{
    return (x+((1<<k)-1))>>k;
}

int HA_279_mul3div4(int x)
{
    return x>>1+x>>2;
}

int HA_280_threefourths(int x)
{
    return (x<<1+x)>>2;
}

void HA_281()
{
    //((1<<w)-1)&(~(1<<k-1))

    //(1<<(k+j)-1)&~(1<<j-1)
}

void HA_282()
{
    /* 
    A   false x=Tmin
    B   true
    C   true
    D   true
    E   true
    */
}

void HA_283()//QE8
{
    /* 先计算y代表的小数值，再计算每次右移K位的值的和
       小数点右移K位，则要加上y代表的整数值
    */
}

unsigned HA_284_f2u(float x)
{
    char * addr=(signed char*)&x;
    unsigned int res;
    for(int i=0; i<sizeof(int); i++)
    {
        res=res|addr[i];
    }
    return res;
}

int HA_284_float_le(float x, float y)
{
    unsigned ux=HA_284_f2u(x);
    unsigned uy=HA_284_f2u(y);

    unsigned sx=ux>>31;
    unsigned sy=uy>>31;

    long val1, val2;

    // 异号
    if(sx<0&&sy>0)return -1;
    else if(sx>0&&sy<0)return 1;
    //同号
    int E1=((ux>>23)&0xFF);
    int E2=((uy>>23)&0xFF);

    int frag1=ux&0x7FFFF;    
    int frag2=uy&0x7FFFF;

    int exp=0;
    // 非规格化
    if(E1==0){
        exp = 1-127;
        val1=frag1<<exp;
    }
    else{// 规格化
        exp = E1-127;
        val1=(frag1|(1<<24))<<exp;
    }

    if(E2==0){
        exp = 1-127;
        val2=frag2<<exp;
    }
    else{
        exp = E2-127;
        val2=(frag2|(1<<24))<<exp;
    }
    
    if(val1<val2)
    {
        if(sx==0)return -1;
        else return 1;
    }
    else{
        if(sx==0)return 1;
        else return -1;
    }
}

void HA_285()
{
    //A  7.0 S 0 E 129 F 11000000000000000000000  0 1000 0001 110 0000 0000 0000 0000 0000
    //B  0 1001 0110 111 1111 1111 1111 1111 1111
    //C  最小规格化数：0 0000 0001 000 0000 0000 0000 0000 0001;    倒数：0 1111 0011 000 0000 0000 0000 0000 0000  
}

void HA_286()
{
    /**
     * 0 0000 0000 0000 000 0 000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000; 0.1*2^(-16379)
     * 0 0000 0000 0000 000 1 000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000; 1*2^(-16335)
     * 0 1111 1111 1111 111 1 111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111; 2^16433-2^16368
     */
}

void HA_289()
{
/**
 * A true
 * B true
 * C false
 * D false
 * E false? x=0?
 * 
 */
}

typedef unsigned float_bits;

float_bits HA_292_float_negate(float_bits f)
{
    unsigned sign=f>>31;
    unsigned exp=f>>23&0xff;
    unsigned frac=f&0x7fffff;

    if(exp==255&&frac!=0)return f;
    sign=!sign;
    return (sign<<31)|(exp<<23)|(frac);
}

float_bits HA_293_float_absval(float_bits f)
{
    unsigned sign=f>>31;
    unsigned exp=f>>23&0xff;
    unsigned frac=f&0x7fffff;
    if(exp==255)return f;
    if(sign==1)return (exp<<23)|frac;
    return f;
}

float_bits HA_294_float_twice(float_bits f)
{
    unsigned sign=f>>31;
    unsigned exp=f>>23&0xff;
    unsigned frac=f&0x7fffff;
    if(exp==255)return f;
    return (sign<<31)|((exp+1)<<23)|frac;
}

float_bits HA_295_float_half(float_bits f)
{
    unsigned sign=f>>31;
    unsigned exp=f>>23&0xff;
    unsigned frac=f&0x7fffff;
    if(exp==255)return f;
    return (sign<<31)|((exp-1)<<23)|frac;
}

int HA_296_float_f2i(float_bits f)
{
    int transMax=0x7F7FFFFF;
    unsigned exp=(f>>23)&0xff;
    if(f>transMax|exp==255)return 0x80000000;
    unsigned frac=f&0x7fffff;
    frac=frac|0x800000;
    frac<<(exp-127);
    return (int)frac;
}

float_bits HA_297_float_i2f(int i)
{
    // 0 1111 1110 111 1111 1111 1111 1111 1111 
    // 0111 1111 1111 1111 1111 1111 0000 0000
    // 0 1000 1000 011 1111 1111 1111 1111 1111
    if(i==0)return 0x00000000;
    unsigned sign, exp, frac;
    sign=(i>>31)&0x01;
    frac=(i>>9)&0x7fffff;
    exp=i&0xff+127;
    
    return (sign<<31)|(exp<<23)|frac;
}

int main(int argc, char** argv)
{
    int a=0, b=0, c=0;
    float a1, b1, c1;
    if(argc==2)
    {   
        a=strtol(argv[1], NULL, 0);

        a1=strtof(argv[1], NULL);
    }
    else if(argc==3)
    {
        a=strtol(argv[1], NULL, 0);
        b=strtol(argv[2], NULL, 0);

        a1=strtof(argv[1], NULL);
        b1=strtof(argv[2], NULL);
    }
    else if(argc==3)
    {
        a=strtol(argv[1], NULL, 0);
        b=strtol(argv[2], NULL, 0);
        c=strtol(argv[3], NULL, 0);

        a1=strtof(argv[1], NULL);
        b1=strtof(argv[2], NULL);
        c1=strtof(argv[3], NULL);
    }
    HA_284_float_le(a1, b1);
    printf("a1=0x%x result=0x%x\n", a, HA_295_float_half(a));
    //printf("result=0x%x\n", HA_268_lower_onr_mask(a));
    return -1;
}

