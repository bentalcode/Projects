#ifndef PARSING_POLICY_TYPE_H_8fbe1bde_1b83_43e6_add2_9b3aec70b9ba
#define PARSING_POLICY_TYPE_H_8fbe1bde_1b83_43e6_add2_9b3aec70b9ba

namespace tabular_data {

/**
 * The ParsingPolicyType class defines various types of Parsing policies.
 */
enum class ParsingPolicyType { 
	IGNORE_ERRORS, 
	FAIL_ON_FIRST_ERROR, 
	FAIL_ON_ERROR_THRESHOLD 
};

} // namespace tabular_data

#endif // PARSING_POLICY_TYPE_H_8fbe1bde_1b83_43e6_add2_9b3aec70b9ba
