/* listing 1.4 Calculate frequency of a MIDI Note Number from cl args */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[])
{
  double c0, c5, semitone_ratio, frequency;
  int midinote;                 /* could be a char */

  semitone_ratio = pow(2, 1.0/12);
  c5 = 220.0 * pow(semitone_ratio, 3);
  c0 = c5 * pow(0.5, 5);

  if (argc != 2) {
    printf("cpsmidi : converts MIDI note to frequency.\n");
    printf("usage: cpsmidi MIDInote\n");
    printf(" range: 0 <= MIDInote <= 127 \n");
    return 1;
  }

  midinote = atoi(argv[1]);

  if (midinote < 0) {
    printf("Bad MIDI note value: %s\n", argv[1]);
    return 1;
  }

  if (midinote > 127) {
    printf("%s is beyond the MIDI range!\n", argv[1]);
    return 1;
  }

  frequency = c0 * pow(semitone_ratio, midinote);
  printf("frequency of MIDI note %d = %f\n", midinote, frequency);
  return 0;
}
