#ifndef DURATION_DISPLAY_17522e12_9d3e_490a_ac2f_eb04d1958b1e
#define DURATION_DISPLAY_17522e12_9d3e_490a_ac2f_eb04d1958b1e

#include "Duration.h"
#include "ModelConstants.h"
#include <iosfwd>
#include <iomanip>

namespace VideoRenderingVisualizer { 
    
    namespace Model {

        /**
         * The DurationDisplay class implements display infromation for duration.
         */
        class DurationDisplay final {
        public:
            /**
             * The DurationDisplay constructor.
             */
            explicit DurationDisplay(const base::DurationSharedPtr duration);

            /**
             * The DurationDisplay destructor.
             */
            ~DurationDisplay();

            /**
             * Gets duration.
             */
            const base::DurationSharedPtr GetDuration() const;

        private:
            base::DurationSharedPtr m_duration;
        };

        /**
         * Writes display information to an output stream.
         */
        inline std::wostream& operator<<(std::wostream& stream, const DurationDisplay& display)
        {
            const base::DurationSharedPtr duration = display.GetDuration();
            double durationInMinutes = 0.0;

            if (duration != nullptr) {
                double durationInSeconds = duration->ToSeconds();
                durationInMinutes = durationInSeconds / 60;
            }

            stream << ModelConstants::DURATION_PROPERTY << ModelConstants::DELIMITER;

            if (duration != nullptr) {
                stream
                    << std::setprecision(ModelConstants::DURATION_PRECISION) << durationInMinutes
                    << ModelConstants::DELIMITER << ModelConstants::DURATION_TIME_UNIT;
            } else {
                stream
                    << ModelConstants::IN_PROGRESS;
            }

            return stream;
        }

    } // namespace Model

} // namespace VideoRenderingVisualizer

#endif // DURATION_DISPLAY_17522e12_9d3e_490a_ac2f_eb04d1958b1e
