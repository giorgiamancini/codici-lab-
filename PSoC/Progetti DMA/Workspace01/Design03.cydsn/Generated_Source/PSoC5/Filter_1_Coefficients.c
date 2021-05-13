#include "Filter_1.h"
#include "Filter_1_PVT.h"


/*******************************************************************************
* ChannelA filter coefficients.
* Filter Type is: Biquad
*******************************************************************************/

/* Renamed array for backward compatibility.
*  Should not be used in new designs.
*/
#define ChannelABiquadCoefficients Filter_1_ChannelABiquadCoefficients

/* Number of Biquad sections are: 1 */

const uint8 CYCODE Filter_1_ChannelABiquadCoefficients[Filter_1_BIQUAD_A_SIZE] = 
{
 /* Coefficients of Section 0 */
 0x6Fu, 0x04u, 0x00u, 0x00u, /* Section(0)_A0, 0.000270605087280273 */

 0xDEu, 0x08u, 0x00u, 0x00u, /* Section(0)_A1, 0.000541210174560547 */

 0x6Fu, 0x04u, 0x00u, 0x00u, /* Section(0)_A2, 0.000270605087280273 */

 0x02u, 0x58u, 0x7Cu, 0x00u, /* Section(0)_B1, -1.94287157058716 */

 0x56u, 0x96u, 0xC3u, 0x00u, /* Section(0)_B2, 0.943949222564697 */
};

