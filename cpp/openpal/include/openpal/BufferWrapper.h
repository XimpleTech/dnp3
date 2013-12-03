
//
// Licensed to Green Energy Corp (www.greenenergycorp.com) under one or
// more contributor license agreements. See the NOTICE file distributed
// with this work for additional information regarding copyright ownership.
// Green Energy Corp licenses this file to you under the Apache License,
// Version 2.0 (the "License"); you may not use this file except in
// compliance with the License.  You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// This file was forked on 01/01/2013 by Automatak, LLC and modifications
// have been made to this file. Automatak, LLC licenses these modifications to
// you under the terms of the License.
//

#ifndef __BUFFER_WRAPPER_H_
#define __BUFFER_WRAPPER_H_

#include <cstddef>
#include <cstdint>

namespace openpal
{

class HasSize
{

public:
	HasSize(size_t aSize);

	size_t Size() const;

	bool IsEmpty() const;

	bool IsNotEmpty() const;

protected:

	size_t mSize;

};

	
class ReadOnlyBuffer : public HasSize
{

public:

	ReadOnlyBuffer();
	ReadOnlyBuffer(uint8_t const* apBuffer, size_t aSize);

	void CopyTo(uint8_t* apDest) const;

	void Advance(size_t aNum);

	operator uint8_t const *() const { return mpBuffer; };

private:
	uint8_t const* mpBuffer;
	
};

class WriteBuffer : public HasSize
{
	public:

    WriteBuffer();
	WriteBuffer(uint8_t* apBuffer, size_t aSize);

	void Clear();

	void Advance(size_t aNum);

	ReadOnlyBuffer ToReadOnly() const;

	operator uint8_t *() { return mpBuffer; };

	private:

	uint8_t* mpBuffer;
};


}

#endif
