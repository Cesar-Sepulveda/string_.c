#include <stdio.h>
#include <string.h>
#include <assert.h>

char *strcpy_(char *s, const char *ct){
  char *pstart = s;
  while((*s++ = *ct++) != '\0'){}
  return pstart;
}

char *strncpy_(char *s, const char *ct, int n){
  char *pstart = s;
  while((*s = *ct)!= '\0' && n-- > 0 ){
    ++s, ++ct;
  }
  while(n-- > 0){
    *s++ = ' ';
  }
  *s = '\0';
  return pstart;
}

char * strcat_(char *s, const char *ct){
  char *pstart = s;
  while(*s != '\0'){ ++s;}
  while((*s++ = *ct++) != '\0'){}
  return pstart;
}

char * strncat_(char *s, const char *ct, int n){
  char *pstart = s;
  while(*s != '\0'){++s;}
  while((*s = *ct)!= '\0' && n-- > 0 ){
    ++s, ++ct;
  }while(n-- > 0){
    *s++ = ' ';
  }
  *s = '\0';
  return pstart;
}

int strcmp_(const char *cs, const char *ct){
  while(*cs == *ct && *cs != '\0' && *ct != '\0'){
    ++cs;
    ++ct;
  }
  if(*cs == '\0' || *ct == '\0'){return 0;}
  else{return *cs - *ct;}
}

int strncmp_(const char *cs, const char *ct, int n){
  while(*cs == *ct && *cs != '\0' && *ct != '\0' && n-- > 0){
      ++cs;
      ++ct;
    }
  if(n == 0){return 0;}
  else{return *cs - *ct;}
}

void test_strcpy(char *s, const char *t, int i){
  printf("strcpy & strncpy:\n");

  strcpy_(s,t);
  assert(strcmp(s,t) == 0);
  printf("%s\n",s);

  strncpy_(s,t,3);
  assert(strncmp(s,t,3) == 0);
  printf("%s\n",s);

  printf("Assertions passed\n");
}

void test_strcat(char *s, const char *t, int i){
  printf("strcat & strncat: \n");

  char *copy = strcat_(s,t);
  assert(strcat(s,t) == copy);
  printf("%s\n",s);

  copy = strncat(s,t, 3);
  assert(strncat(s,t,3) == copy);
  printf("%s\n",s);

  printf("Assertions passed\n");
}

void test_strcmp(const char *s, const char *t, int i){
  printf("strcmp & strncmp:\n");

  int j = 0;
  j = strcmp_(s,t);
  assert(strcmp(s,t) >=  j);
  printf("%i\n", j);

  j = strncmp_(s,t,3);
  assert(strncmp(s,t,3) == j);
  printf("%i\ns", j);

  printf("Assertions passed\n");
}

  int main (){
  char buf1[100] = "cat";
  char buf2[100] = "bison";
  test_strcpy(buf1,buf2, 3);

  char buf3[100] = "dog";
  char buf4[100] = "food";
  test_strcat(buf3, buf4, 3);

  char buf5[100] = "what";
  char buf6[100] = "whale";
  test_strcmp(buf5, buf6, 3);

  return 0;
}
