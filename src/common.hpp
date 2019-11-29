#ifndef _COMMON_H
#define _COMMON_H

#include <boost/asio.hpp>
#include <boost/safe_numerics/safe_integer.hpp>
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
using suint32 = boost::numeric::safe<uint32>;
using uint64 = std::uint64_t;

class ByteBuffer : std::enable_shared_from_this<ByteBuffer>
{
public:
	ByteBuffer();
	ByteBuffer(ByteString&);
	ByteBuffer&& clone(std::size_t) const;
	ByteString& getBytes() const;
	void setBytes(ByteString&);
	void flush();
	template <class StringType> StringType&& read(std::size_t);
	Byte readByte();
	int16 readI16();
	int32 readI32();
	void readNull(std::size_t);
	std::string&& readString();
	uint16 readU16();
	uint32 readU32();
	template <class StringType> void write(const StringType&);
	void writeByte(Byte);
	void writeI16(int16);
	void writeI32(int32);
	void writeNull(std::size_t);
	void writeString(std::string_view);
	void writeU16(uint16);
	void writeU32(uint32);
private:
	ByteString data;
	ByteString::iterator position;
};

using ByteBufferPtr = std::shared_ptr<ByteBuffer>;

#endif // _COMMON_H
