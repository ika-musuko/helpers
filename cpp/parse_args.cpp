/* simple argument parser similar to python's argparse.ArgumentParser
 *
 * Parses command-line arguments into a key-value map.
 *
 * Expects each flag (using double dashes, e.g., "--input") to be immediately
 * followed by its value. Note that single-dash flags (e.g., "-i") are not
 * treated as equivalent to double-dash flags.
 *
 * @param args Map of argument flags to values; may be pre-populated with defaults.
 * @param required_args List of required flags (e.g., "--input"). Throws an exception if any are missing.
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line argument strings.
 *
 * @throws std::runtime_error if any required flag is missing.
 *
 * @example
 * std::unordered_map<std::string, std::string> args = { {"--output", "default.txt"} };
 * std::vector<std::string> required = {"--input"};
 * parse_args(args, required, argc, argv);
 *
 * std::cout << args["--input"] << std::endl; // usage
 */
void parse_args(
    std::unordered_map<std::string, std::string>& args, // pass in args with default values here
    const std::vector<std::string>& required_args,
    int argc,
    char** argv
) {
    std::string flag;
    for (int a = 1; a < argc; ++a) {
        std::string arg = argv[a];
        if (arg[0] == '-') {
            flag = arg;
        } else {
            args[flag] = arg;
        }
    }

    std::vector<std::string> missing;
    for (const std::string& required : required_args) {
        if (args.find(required) == args.end()) {
            missing.push_back(required);
        }
    }

    if (!missing.empty()) {
        std::ostringstream oss;
        oss << "Missing required arguments:";
        for (const auto& arg : missing) {
            oss << " " << arg;
        }
        throw std::runtime_error(oss.str());
    }
}
