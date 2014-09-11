#pragma once
#include"PrimitivePipeline.h"
#include"ShaderManager.h"
#include"FrameBuffer.h"
#include<functional>
#include<memory>

class EffectClass
{
public:
	EffectClass();
	~EffectClass();

	HRESULT Initialize(ID3D11Device* device,
		ID3D11DeviceContext* context);
	void Shutdown();

	void clearRenderTarget(ID3D11Device* device,
		ID3D11DeviceContext* context);

	void setRenderTarget(ID3D11Device* device,
		ID3D11DeviceContext* context);

	void bindVS(ID3D11Device* device,
		ID3D11DeviceContext* context,
		unsigned int textureSlot);

	void bindPS(ID3D11Device* device,
		ID3D11DeviceContext* context,
		unsigned int textureSlot);

	void clearDepthStencil(ID3D11Device* device,
		ID3D11DeviceContext* context);

	bool isInited()const;


	//void Render
	//Call the renderFunction function in argument-list to render Objects.
protected:
	std::unique_ptr<FrameBuffer> fbo;
	bool is_init;
private:
	template<typename T>
	struct func_type_wrapper
	{
		typedef T type;
	};
};
