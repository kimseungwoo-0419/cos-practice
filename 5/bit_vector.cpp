#include <cstdio>
#include <cstdlib>
#include <cstring>
#define BIT_VECTOR_LENGTH 4
#define MSB_INDEX BIT_VECTOR_LENGTH - 1
#define LSB_INDEX 0

void print_command(char *argv[]);
//int check_validity(char *input);
void init_bit_vector(char *input, char *bv);
void print_bit_vector(char *bv);
void bit_addition(char *bv, char *bv2, char *result);
unsigned int unsigned_addition(char *bv1, char *bv2);
int twos_complement_addition(char *bv1, char *bv2);
int ones_complement_addition(char *bv1, char *bv2);
int sign_magnitued_addition(char *bv1, char *bv2);



int exp(int b, int e)
{
    int i, ret;
    ret = 1;
    for (i =0; i<e; i++)
    {
        ret *= b;
        
    }
    return ret;
}

unsigned int b2u(char *bv)
{
    int i;
    unsigned int ret;
    ret = 0;


    for (i = LSB_INDEX; i <= MSB_INDEX; i++)
    {
        ret += bv[i] * exp(2, i);
    }
    return ret;

}

// int b2s(char *bv)
// {
//     int i , sign, ret;
//     ret = 0;
//     sign = exp(-1, bv[MSB_INDEX]);
//     for (i = LSB_INDEX; i<MSB_INDEX; i++)
//     {
//         ret += bv[i] * exp(2, i);
        
//     }
//     ret *= sign;
//     return ret;
// }

int b2s(char *bv)
{
    int i, ret = 0;

    for (i = LSB_INDEX; i <= MSB_INDEX; i++)
    {
        ret += bv[i] * exp(2, i);
    }

    // MSB가 1이면 음수이므로 보정
    if (bv[MSB_INDEX] == 1)
    {
        ret -= exp(2, BIT_VECTOR_LENGTH);
    }

    return ret;
}


int b2o(char *bv)
{
    int i, term, ret;
    ret = 0;
    term = -1 * bv[MSB_INDEX] * (exp(2, MSB_INDEX) - 1);
    for (i=LSB_INDEX; i<MSB_INDEX; i++)
    {
        ret += bv[i]*exp(2, i);
    }
    ret += term;




    return ret;

}
int b2t(char *bv)
{
    int i, term, ret;
    ret = 0;
    term = -1 * bv[MSB_INDEX] * exp(2, MSB_INDEX);
    for (i = LSB_INDEX; i<MSB_INDEX; i++)
    {
        ret += bv[i]*exp(2, i);
    }
    ret += term;

    return ret;

}


void bit_addition(char *bv, char *bv2, char *result)
{


    int i;
    char carry[BIT_VECTOR_LENGTH+1] = {0, };
    char sum;


    for (i=LSB_INDEX; i<MSB_INDEX;i++)
    {
        sum = bv[i] + bv2[i] + carry[i];
       
        if(sum == 0)
        {
            result[i] = 0;
            carry[i+1] = 0;

        }   
        else if (sum == 2)
        {
            result[i] = 1;
            carry[i+1] = 0;
        }   
        else if (sum == 2)
        {
            result[i] = 0;
            carry[i+1] = 1;
        }   
        else{
            result[i] = 1;
            carry[i+1] = 1;
        }


    }    



}
unsigned int unsigned_addition(char *bv1, char *bv2)
{
    char result[BIT_VECTOR_LENGTH];
    bit_addition(bv1, bv2, result);

    return b2u(result);
}

int twos_complement_addition(char *bv1, char *bv2)
{

    char result[BIT_VECTOR_LENGTH];
    bit_addition(bv1, bv2, result);

    return b2t(result);

}
int ones_complement_addition(char *bv1, char *bv2)
{
    char result[BIT_VECTOR_LENGTH];
    bit_addition(bv1, bv2, result);

    return b2o(result);
}
int sign_magnitued_addition(char *bv1, char *bv2)
{
    char result[BIT_VECTOR_LENGTH];
    bit_addition(bv1, bv2, result);

    return b2s(result);
}





void print_command(char *argv[])
{
    printf("Command: %s <first bit vector> <second bit vector>\n", argv[0]);
    printf("Example: %s 0110 1000\n", argv[0]);
    exit(1);
}





void init_bit_vector(char *input, char *bv)
{
    int i, len;
    char c;
    len = strlen(input);

    for (i = 0; i < len; i++)
    {

        c = input[i];
        if ( c == '0')
            bv[MSB_INDEX-i] = 0;
        else
            bv[MSB_INDEX-i] = 1;
    }
}

void print_bit_vector(char *bv)
{
    int i;


    printf("Bit Vector");
    for (i = MSB_INDEX; i >= LSB_INDEX; i--)
    {
        printf("%d", bv[i]);
    }
    printf("\n");
}




int main(int argc, char *argv[])
{
    char bv1[BIT_VECTOR_LENGTH];
    char bv2[BIT_VECTOR_LENGTH];

    // if (argc != 3)
    // {
    //     printf("Error: invalid number of arguments\n");
    //     print_command(argv);
    // }

    // if (!(check_validity(argv[1]) && check_validity(argv[2])))
    // {
    //     printf("Error: invalid arguments\n");
    //     print_command(argv);
    // }

    init_bit_vector(argv[1], bv1);
    init_bit_vector(argv[2], bv2);
    print_bit_vector(bv1);
    printf("- B2U: %u\n", b2u(bv1));
    printf("- B2S: %u\n", b2s(bv1));
    printf("- B2O: %u\n", b2o(bv1));
    printf("- B2T: %u\n", b2t(bv1));

    print_bit_vector(bv2);
    printf("- B2U: %u\n", b2u(bv2));
    printf("- B2S: %u\n", b2s(bv2));
    printf("- B2O: %u\n", b2o(bv2));
    printf("- B2T: %u\n", b2t(bv2));

    printf("Addition >>> \n");
    printf("- Unsigned addition: %u\n", unsigned_addition(bv1, bv2));
    printf("- sign_magnitued_addition: %u\n", sign_magnitued_addition(bv1, bv2));
    printf("- twos_complement_addition: %u\n", twos_complement_addition(bv1, bv2));
    

    return 0;
}



