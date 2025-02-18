class Timer {
public:
    explicit Timer(const std::string& name = "Section")
        : _name(name)
        , _start(std::chrono::high_resolution_clock::now()) 
    {
    }

    ~Timer() {
        auto end = std::chrono::high_resolution_clock::now();

        auto total_time = end - _start;

        auto total_time_ms = std::chrono::duration_cast<std::chrono::milliseconds>(total_time).count();
        auto total_time_sec = std::chrono::duration_cast<std::chrono::seconds>(total_time).count();
        auto mins = total_time_sec / 60;
        auto secs = total_time_sec % 60;

        std::cout << _name << " time: "
            << std::setprecision(3) << total_time_ms << "ms ("
            << std::setprecision(0) << mins << "m" << secs << "s)" << std::endl;
    }

private:
    std::string _name;
    std::chrono::time_point<std::chrono::high_resolution_clock> _start;
};
