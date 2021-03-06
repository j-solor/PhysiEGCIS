//
// PartSource.h
//
// $Id: //poco/1.4/Net/include/Poco/Net/PartSource.h#2 $
//
// Library: Net
// Package: Messages
// Module:  PartSource
//
// Definition of the PartSource class.
//
// Copyright (c) 2005-2006, Applied Informatics Software Engineering GmbH.
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


#ifndef Net_PartSource_INCLUDED
#define Net_PartSource_INCLUDED


#include "Poco/Net/Net.h"
#include "Poco/Net/MessageHeader.h"
#include <istream>


namespace Poco {
namespace Net {


class Net_API PartSource
	/// This abstract class is used for adding parts or attachments
	/// to mail messages, as well as for uploading files as part of a HTML form.
{
public:
	virtual std::istream& stream() = 0;
		/// Returns an input stream for reading the 
		/// part data.
		///
		/// Subclasses must override this method.
		
	virtual const std::string& filename() const;
		/// Returns the filename for the part or attachment.
		///
		/// May be overridded by subclasses. The default
		/// implementation returns an empty string.
	
	const std::string& mediaType() const;
		/// Returns the MIME media type for this part or attachment.
		
	MessageHeader& headers();
		/// Returns a MessageHeader containing additional header
		/// fields for the part.

	const MessageHeader& headers() const;
		/// Returns a MessageHeader containing additional header
		/// fields for the part.

	virtual ~PartSource();
		/// Destroys the PartSource.
	
protected:
	PartSource();
		/// Creates the PartSource, using
		/// the application/octet-stream MIME type.
		
	PartSource(const std::string& mediaType);
		/// Creates the PartSource, using the
		/// given MIME type.

private:
	PartSource(const PartSource&);
	PartSource& operator = (const PartSource&);

	std::string _mediaType;
	MessageHeader _headers;
};


//
// inlines
//
inline const std::string& PartSource::mediaType() const
{
	return _mediaType;
}


inline MessageHeader& PartSource::headers()
{
	return _headers;
}


inline const MessageHeader& PartSource::headers() const
{
	return _headers;
}


} } // namespace Poco::Net


#endif // Net_PartSource_INCLUDED
