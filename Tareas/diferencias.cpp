#include <stdio.h>

int main() {
   int array1[] = {1, 2, 3, 4, 5};
   int array2[] = {3, 4, 5, 6, 7};
   int size1 = sizeof(array1) / sizeof(int);
   int size2 = sizeof(array2) / sizeof(int);
   int difference[size1];
   int k = 0;

   for (int i = 0; i < size1; i++) {
      int found = 0;
      for (int j = 0; j < size2; j++) {
         if (array1[i] == array2[j]) {
            found = 1;
            break;
         }
      }
      if (!found) {
         difference[k++] = array1[i];
      }
   }

   printf("La diferencia de los dos arreglos es: { ");
   for (int i = 0; i < k; i++) {
      printf("%d ", difference[i]);
   }
   printf("}\n");

   return 0;
}
