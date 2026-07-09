#pragma once
using namespace std;


class Icon
{
public:
	static const int TYPE_TERRAIN = 0;
	static const int TYPE_ITEM = 1;

	static const int  IS_GRASS_SIDE = 1;
	static const int  IS_GRASS_TOP = 2;

#ifdef __PSVITA__
	// AP - alpha cut out is expensive on vita so we mark which icons require it
	static const int  IS_ALPHA_CUT_OUT = 4;
#endif

	virtual int getX() const = 0;
	virtual int getY() const = 0;
	virtual int getWidth() const = 0;
	virtual int getHeight() const = 0;
	virtual float getU0(bool adjust = false) const = 0;
	virtual float getU1(bool adjust = false) const = 0;
	virtual float getU(double offset, bool adjust = false) const = 0;
	virtual float getV0(bool adjust = false) const = 0;
	virtual float getV1(bool adjust = false) const = 0;
	virtual float getV(double offset, bool adjust = false) const = 0;
	virtual wstring getName() const = 0;
	virtual int getSourceWidth() const = 0;
	virtual int getSourceHeight() const = 0;
	virtual int getFlags() const = 0;			// 4J added
	virtual void setFlags(int flags) = 0;	// 4J added
};

class FullTextureIcon : public Icon
{
public:
    virtual int getX() const { return 0; }
    virtual int getY() const { return 0; }
    virtual int getWidth() const { return 16; }
    virtual int getHeight() const { return 16; }
    virtual float getU0(bool adjust = false) const { return 0.0f; }
    virtual float getU1(bool adjust = false) const { return 1.0f; }
    virtual float getU(double offset, bool adjust = false) const { return 0.0f; }
    virtual float getV0(bool adjust = false) const { return 0.0f; }
    virtual float getV1(bool adjust = false) const { return 1.0f; }
    virtual float getV(double offset, bool adjust = false) const { return 0.0f; }
    virtual wstring getName() const { return L"full_texture"; }
    virtual int getSourceWidth() const { return 16; }
    virtual int getSourceHeight() const { return 16; }
    virtual int getFlags() const { return 0; }
    virtual void setFlags(int flags) {}
};