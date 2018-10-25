#include <cstdio>

using namespace std;

#define GREATER 1
#define EQUAL 0
#define SMALLER -1
#define MAX 100

FILE *in = fopen("virgule.in", "r");
FILE *out = fopen("virgule.out", "w");

typedef int Huge[MAX];
Huge A, B, C;

bool pos[MAX];
char printable[3*MAX];

void read(){
    char c = ' ';
    int advancedIterator = 1;
    while(c != '\n'){
        fscanf(in, "%c", &c);
        A[advancedIterator++] = (int) c - 48; // Add a digit in the Huge number
        A[0] ++; // Increment the length of the Huge number
    }
    A[0] --;
}

int compare(Huge X, Huge Y){
    if(X[0] > Y[0]){
        return GREATER;
    }
    if(X[0] < Y[0]){
        return SMALLER;
    }

    unsigned short length = X[0];
    for(int i = 1; i <= length; ++i){
        if(X[i] > Y[i]){
            return GREATER;
        }
        if(X[i] > Y[i]){
            return SMALLER;
        }
    }

    return EQUAL;
}

void clean(){
    for(int i = 0; i < MAX; ++i){
        B[i] = 0;
        C[i] = 0;
    }
}

void cleanPos(){
    for(int i = 0; i < MAX; ++i){
        pos[i] = false;
    }
}


void print(){
    for(int i = 1; i <= A[0]; ++i){
        fprintf(out, "%d", A[i]);
        if(pos[i]){
            fprintf(out, ",");
        }
    }
}


bool bkt(int startingPoint, int startingDigits, int leftDigits){
    // Clean the array for the next iteration (B and C are mutable)
    clean();

    // Generate the two Huge numbers
    int it = 1;
    bool zeroBreaker = false;

    int leftPoint = startingPoint - startingDigits;
    for(int i = leftPoint + 1; i <= startingPoint; ++i){
        if(!zeroBreaker && A[i] == 0){
            continue;
        }
        zeroBreaker = true;
        B[it++] = A[i];
        B[0] ++;
    }
    if(B[0] == 0){
        return false;
    }


    it = 1;
    zeroBreaker = false;
    int checker = (leftPoint - leftDigits) + 1;
    if(checker < 1){
        checker = 1;
    }
    for(int i = checker; i <= leftPoint; ++i){
        if(!zeroBreaker && A[i] == 0){
            continue;
        }
        zeroBreaker = true;
        C[it++] = A[i];
        C[0] ++;
    }
    if(C[0] == 0){
        return false;
    }


    // Store the pos array in case of a succesfull search
    pos[startingPoint - startingDigits] = true;

    // See if they respect the logic
    int result = compare(B, C);
    if(result == EQUAL || result == SMALLER){
        if(leftDigits == 1){
            return false;
        }
        else{
            leftDigits --;
        }
    }
    if(leftPoint - leftDigits <= 0){
        // hooray! it's done
        return true;
    }
    bkt(startingPoint-startingDigits, leftDigits, leftDigits);
    return false;
}

void advancedSearch(unsigned short startingPoint, unsigned short startingDigits){
    bool found = bkt(startingPoint, startingDigits, startingDigits);
    if(!found){
        cleanPos();
        advancedSearch(startingPoint, startingDigits + 1);
    }
    else{
        print();
    }
}


int main()
{
    read();
    advancedSearch(A[0], 1);
    return 0;
}
