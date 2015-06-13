#ifndef TURTLE_H_
#define TURTLE_H_

class __declspec(dllexport) Turtle
{
public:
	void Run();
};

int Download();

static bool Upload(const char* file);

#endif // TURTLE_H__
