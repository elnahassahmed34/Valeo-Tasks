#include <iostream>
#include <fstream>
#include <string>
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>

namespace logging = boost::log;

void init_logging() {
    // Set up logging to a file in the same directory as the executable
    logging::add_file_log(
        logging::keywords::file_name = "log_%N.log", // %N is a placeholder for thread ID
        logging::keywords::rotation_size = 10 * 1024 * 1024, // Rotate after 10MB
        logging::keywords::auto_flush = true
    );

    // Only log messages with severity level >= trace
    logging::core::get()->set_filter(
        logging::trivial::severity >= logging::trivial::trace
    );
}

int main() {
    // Initialize logging
    init_logging();

    // Log some messages
    BOOST_LOG_TRIVIAL(trace) << "This is a trace message";
    BOOST_LOG_TRIVIAL(debug) << "This is a debug message";
    BOOST_LOG_TRIVIAL(info) << "This is an info message";
    BOOST_LOG_TRIVIAL(warning) << "This is a warning message";
    BOOST_LOG_TRIVIAL(error) << "This is an error message";
    BOOST_LOG_TRIVIAL(fatal) << "This is a fatal message";

    return 0;
}
