#pragma once
#include <iostream>

/*
class IMessage
{
protected:
	std::string text;
	std::string from;
	std::string to;
	std::string subject;
	char* voice;
public:
	virtual void Send() = 0;
};

class VoiceMessage : public IMessage
{

};

class SmsMessage : public IMessage
{

};
*/

//

class IMessage
{
protected:
	std::string from;
	std::string to;
public:
	virtual void Send() = 0;
};

class IVoiceMessage : public IMessage
{
protected:
	char* voice;
};

class ITextMessage : public IMessage
{
protected:
	std::string text;
};