#include <stdio.h>
#include <string.h>

int mod12(int note) {
  while(note < 0) note +=12;
  while(note >= 12) note -=12;
  return note;
}


int main()
{
  char note[3], **p1, **p2,
    *table[12] = {"C", "C#", "D", "D#",
                  "E", "F", "F#", "G",
                  "G#", "A", "A#", "B"};
  int interval;
  printf("Enter base note (captials, use # for sharps, eg. A#): ");
  scanf("%s", note);
  printf("Enter interval in semitones: ");
  scanf("%d", &interval);
  /* point p1 to the beginning of the array and p2 to its end */
  p1 = table;
  p2 = table+11;
  /* now find the base note position,
   incrementing the pointer until we find it */
  while(strcmp(*p1, note)) {
    p1++;
    if (p1 > p2) {              /* if we're pase the end */
      printf("could not find %s\n", note);
      return 1;
    }
  }
  /* add the interval to the address of the base note */
  p1 += mod12(interval);
  /* if beyond the end of the table, wrap it around */
  if (p1 > p2) p1 -= 12;
  /* print result                           */
  printf("%s transposed by %d semitones is %s\n",
         note, interval, *p1);
  return 0;
}
