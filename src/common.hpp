#ifndef _COMMON_H
#define _COMMON_H

#include <boost/asio.hpp>
#include <chrono>
#include <cstdint>
#include <mutex>
#include <vector>

using Acceptor = boost::asio::ip::tcp::acceptor;
using Byte = std::uint8_t;
using ByteString = std::vector<Byte>;
using Error = boost::asio::error_code;
using int16 = std::int16_t;
using int32 = std::int32_t;
using LockGuard = std::lock_guard<std::mutex>;
using Socket = boost::asio::ip::tcp::socket;
using Strand = boost::asio::io_context::strand;
using Timestamp = std::chrono::time_point<std::chrono::system_clock>;
using uint16 = std::uint16_t;
using uint32 = std::uint32_t;
using uint64 = std::uint64_t;

#endif // _COMMON_H
