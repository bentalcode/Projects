#include "RetryPolicy.h"
#include "SmartPointers.h"

using namespace client_server;

const unsigned int RetryPolicy::DEFAULT_NUM_OF_ATTEMPTS = 5;
const base::DurationSharedPtr RetryPolicy::DEFAULT_DURATION = base::Duration::FromSeconds(5);

/**
 * Creates a default retry policy.
 */
IRetryPolicySharedPtr RetryPolicy::MakeDefault()
{
    return Make(
        DEFAULT_NUM_OF_ATTEMPTS,
        DEFAULT_DURATION);
}

/**
 * Creates a retry policy.
 */
IRetryPolicySharedPtr RetryPolicy::Make(
    unsigned int numOfAttempts,
    base::DurationSharedPtr intervalDuration)
{
    return std::make_shared<RetryPolicy>(
        numOfAttempts,
        intervalDuration);
}

/**
 * The RetryPolicy constructor.
 */
RetryPolicy::RetryPolicy(
    unsigned int numOfAttempts,
    base::DurationSharedPtr intervalDuration) :
    m_numOfAttempts(numOfAttempts),
    m_intervalDuration(intervalDuration)
{
}

/**
 * The RetryPolicy destructor.
 */
RetryPolicy::~RetryPolicy()
{
}

/**
 * Gets the number of attempts.
 */
unsigned int RetryPolicy::GetNumberOfAttempts() const
{
    return m_numOfAttempts;
}

/**
 * Gets the interval duration.
 */
base::DurationSharedPtr RetryPolicy::GetIntervalDuration() const
{
    return m_intervalDuration;
}
