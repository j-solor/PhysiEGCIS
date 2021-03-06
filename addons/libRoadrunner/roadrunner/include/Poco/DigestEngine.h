//
// DigestEngine.h
//
// $Id: //poco/1.4/Foundation/include/Poco/DigestEngine.h#1 $
//
// Library: Foundation
// Package: Crypt
// Module:  DigestEngine
//
// Definition of class DigestEngine.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef Foundation_DigestEngine_INCLUDED
#define Foundation_DigestEngine_INCLUDED


#include "Poco/Foundation.h"
#include <vector>


namespace Poco {


class Foundation_API DigestEngine
	/// This class is an abstract base class
	/// for all classes implementing a message
	/// digest algorithm, like MD5Engine
	/// and SHA1Engine.
	/// Call update() repeatedly with data to
	/// compute the digest from. When done,
	/// call digest() to obtain the message
	/// digest.
{
public:
	typedef std::vector<unsigned char> Digest;

	DigestEngine();
	virtual ~DigestEngine();
		
	void update(const void* data, std::size_t length);
	void update(char data);
	void update(const std::string& data);
		/// Updates the digest with the given data.
		
	virtual std::size_t digestLength() const = 0;
		/// Returns the length of the digest in bytes.

	virtual void reset() = 0;
		/// Resets the engine so that a new
		/// digest can be computed.
		
	virtual const Digest& digest() = 0;
		/// Finishes the computation of the digest and
		/// returns the message digest. Resets the engine
		/// and can thus only be called once for every digest.
		/// The returned reference is valid until the next
		/// time digest() is called, or the engine object is destroyed.

	static std::string digestToHex(const Digest& bytes);
		/// Converts a message digest into a string of hexadecimal numbers.

	static Digest digestFromHex(const std::string& digest);
		/// Converts a string created by digestToHex back to its Digest presentation

protected:
	virtual void updateImpl(const void* data, std::size_t length) = 0;
		/// Updates the digest with the given data. Must be implemented
		/// by subclasses.
		
private:
	DigestEngine(const DigestEngine&);
	DigestEngine& operator = (const DigestEngine&);
};


//
// inlines
//


inline void DigestEngine::update(const void* data, std::size_t length)
{
	updateImpl(data, length);
}


inline void DigestEngine::update(char data)
{
	updateImpl(&data, 1);
}


inline void DigestEngine::update(const std::string& data)
{
	updateImpl(data.data(), data.size());	
}


} // namespace Poco


#endif // Foundation_DigestEngine_INCLUDED
