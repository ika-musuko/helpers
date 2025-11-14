parse_args() {
    # usage:
    #   parse_args "$@"
    #
    # returns:
    #   sets a bunch of variables prefixed with ARG_ based on the command line args
    #   - @@my-arg -> ARG_my_arg=1
    #   - --my-arg value -> ARG_my_arg="value"
    #   - value -> ARG_1="value", ARG_2="value", etc...
    #

    # parse
    local token
    local position=1

    local is_parsing_flag_value
    local flag_name
    to_flag_name() {
        local token="$1"
        token="${token#--}"
        token="${token#@@}"
        token="${token//-/_}"
        echo "ARG_$token"
    }

    while [[ $# -gt 0 ]]; do
        token="$1"

        if [ -n "$is_parsing_flag_value" ]; then
            printf -v "$flag_name" '%s' "$token"
            unset is_parsing_flag_value

        elif [[ $token == --* ]]; then # --my-arg value
            flag_name=$(to_flag_name "$token")
            is_parsing_flag_value=1

        elif [[ $token == \@\@* ]]; then # @@my-arg
            flag_name=$(to_flag_name "$token")
            printf -v "$flag_name" '%s' 1

        else
            printf -v "ARG_$position" '%s' "$token"
            position=$((position+1))

        fi

        shift
    done
}

