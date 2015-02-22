/* listing 1.3.2 find nearest MIDI note to a given frequency in Hz */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  double semitone_ratio;
  double c0;                    /* frequency of MIDI Note 0 */
  double c5;                    /* frequency of Middle C */
  double frequency;             /* ... which we want to find, */
  int midinote;                 /* ... given this note.  */
  double fracmidi;
  char message[256];

  /* calculate required numbers              */

  semitone_ratio = pow(2, 1/12.0); /* approx. 1.0594631 */
  /* find Middle C, three semitones above low A = 220 */
  c5 = 220.0 * pow(semitone_ratio, 3);
  /* MIDI Note 0 is C, 5 octaves below Middle C */
  c0 = c5 * pow(0.5, 5);

  printf("Enter frequency: ");

  if (gets(message) == NULL) {
    printf("There was an error reading the input.\n");
    return 1;
  }

  if (message[0] == '\0') {
    printf("Have a nice day!\n");
  }

  frequency = atof(message);
  if (frequency < 0) {
    printf("Sorry - %s is a bad frequency\n", message);
    return 1;
  }

  fracmidi = log(frequency / c0) / log(semitone_ratio);
  midinote = (int) (fracmidi + 0.5);
  printf("The nearest MIDI note to the frequency %f is %d\n", frequency, midinote);

  return 0;
}
