#ifndef MedianFilter_h

   #define MedianFilter_h

   #include "Arduino.h"

   class MedianFilter
   {
      public:
         MedianFilter(int size, int seed);
         int in(const int & value);
         int out();

         int getMin();
         int getMax();
         int getMean();
         int getStDev();

      private:
         uint8_t medFilterWin;      // number of samples in sliding median filter window - usually odd #
         uint8_t medDataPointer;	   // mid point of window
         int     * data;			   // array pointer for data sorted by age in ring buffer
         uint8_t * sizeMap;			// array pointer for locations data in sorted by size
         uint8_t * locationMap;		// array pointer for data locations in history map
         uint8_t oldestDataPoint;	// oldest data point location in ring buffer
         int32_t totalSum;
   };

#endif
