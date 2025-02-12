#pragma once

// DirectX11 헤더.
#include <d3d11.h>
#include <dxgi.h>
#include <memory>

#include "../Core/Type.h"

namespace Blue
{
	// 그래픽카드에서 처리하는 일/리소스를 관리하는 클래스.
	// RHI - Render Hardware Interface.
	class Renderer
	{
		// 엔진 클래스 friend 선언.
		friend class Engine;

	public:
		Renderer(uint32 width, uint32 height, HWND window);
		~Renderer();

		// 그리기 함수.
		void Draw();

	private:
		// 리소스.
		// 장치류.
		ID3D11Device* device = nullptr;
		// 그래픽카드에서 그리라는 명령을 담당하는 포인터.
		ID3D11DeviceContext* context = nullptr;
		// 백 버퍼 관리하는 포인터.
		IDXGISwapChain* swapChain = nullptr;

		// 버퍼.
		ID3D11RenderTargetView* renderTargetView = nullptr;
		
		// 뷰포트.
		D3D11_VIEWPORT viewport;

		// @Temp: 임시.
		// 정점 버퍼 (정점 정보를 전달하는 데 사용함).
		ID3D11Buffer* vertexBuffer = nullptr;
		
		// 인덱스 버퍼 (정점을 조립할 때 정점의 순서를 전달).
		ID3D11Buffer* indexBuffer = nullptr;

		// 쉐이더 객체.
		//std::unique_ptr<class Shader> shader;

		// 삼각형 메시 객체.
		std::unique_ptr<class TriangleMesh> mesh;

		// 사각형 메시 객체.
		std::unique_ptr<class QuadMesh> qmesh;
	};
}