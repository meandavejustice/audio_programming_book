/* listing 1.3. Calculate frequency of a MIDI Note Number from user input */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  double c0, c5, semitone_ratio, frequency;
  int midinote;

  semitone_ratio = pow(2, 1.0/12);
  c5 = 220.0 * pow(semitone_ratio, 3);
  c0 = c5 * pow(0.5, 5);

  printf("Enter MIDI note (0 - 127): ");
  scanf("%d", &midinote);

  if (midinote < 0) {
    printf("Sorry - %d is a bad MIDI note number\n", midinote);
    return 1;
  }

  if (midinote > 127) {
    printf("Sorry - %d is beyond the MIDI range!\n", midinote);
    return 1;
  }

  frequency = c0 * pow(semitone_ratio, midinote);
  printf("frequency of MIDI note %d = %f\n", midinote, frequency);

  return 0;
}
