#pragma once

#define OFX_ANIMATION_PRIMITIVES_BEGIN_NAMESPACE namespace ofx { namespace AnimationPrimitives {
#define OFX_ANIMATION_PRIMITIVES_END_NAMESPACE } }


OFX_ANIMATION_PRIMITIVES_BEGIN_NAMESPACE

#pragma mark - Vector Helper

template <typename T>
struct _$ : public vector<T>
{
	_$& operator,(const T& t)
	{
		this->push_back(t);
		return *this;
	}
};

#define $(type, ...) (_$<type>(), __VA_ARGS__)
#define $f(...) $(float, __VA_ARGS__)
#define $i(...) $(int, __VA_ARGS__)
#define $ui(...) $(unsigned int, __VA_ARGS__)
#define $v2(...) $(ofVec2f, __VA_ARGS__)
#define $v3(...) $(ofVec3f, __VA_ARGS__)
#define $v4(...) $(ofVec4f, __VA_ARGS__)

#pragma mark - misc

template<typename T>
struct Type2Int {
	static unsigned int value() {
		static size_t m = 0;
		return (unsigned int)&m;
	}
};

OFX_ANIMATION_PRIMITIVES_END_NAMESPACE

namespace ofxAnimationPrimitives = ofx::AnimationPrimitives;