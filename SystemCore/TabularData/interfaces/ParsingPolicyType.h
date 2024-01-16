#pragma once

namespace TabularData {

/**
 * The ParsingPolicyType class defines various types of Parsing policies.
 */
enum class ParsingPolicyType { 
	IGNORE_ERRORS, 
	FAIL_ON_FIRST_ERROR, 
	FAIL_ON_ERROR_THRESHOLD 
};

} // namespace TabularData