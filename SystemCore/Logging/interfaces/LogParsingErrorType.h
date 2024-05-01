#ifndef I_LOG_PARSING_ERROR_TYPE_H_d2aa28ea_8b1e_4e79_b612_994d8cfc7a45
#define I_LOG_PARSING_ERROR_TYPE_H_d2aa28ea_8b1e_4e79_b612_994d8cfc7a45

namespace logging {

	/**
	 * The LogParsingErrorType class defines various types of errors when parsing logs.
	 */
	enum class LogParsingErrorType {
		INVALID_QUERY_SYNTAX,        // The query specified in the command is invalid.
		INPUT_FORMAT_ERRORS,         // The specified Input Format has encountered an error that prevents it from generating input records.
		TRANSFORMATION_FORMAT_ERRORS // the specified Transformation Format has encountered an error that prevents it to transform real records.
	};

} // namespace logging

#endif // I_LOG_PARSING_ERROR_TYPE_H_d2aa28ea_8b1e_4e79_b612_994d8cfc7a45
