#include "videodriver.h"

IVideoDriver *GetVideoFromIntPtr(IntPtr videodriver)
{
    return (IVideoDriver*) videodriver;
}

bool VideoDriver_BeginScene(IntPtr videodriver, bool backBuffer, bool zBuffer, M_SCOLOR color)
{
    _FIX_BOOL_MARSHAL_BUG(GetVideoFromIntPtr(videodriver)->beginScene(backBuffer, zBuffer, MU_SCOLOR(color)));
}

void VideoDriver_EndScene(IntPtr videodriver)
{
    GetVideoFromIntPtr(videodriver)->endScene();
}

IntPtr VideoDriver_AddTexture(IntPtr videodriver, M_DIM2DS size, c8* name, ECOLOR_FORMAT fmt)
{
    return GetVideoFromIntPtr(videodriver)->addTexture(MU_DIM2DS(size), name, fmt);
}

IntPtr VideoDriver_GetGPUProgrammingServices(IntPtr videodriver)
{
    return GetVideoFromIntPtr(videodriver)->getGPUProgrammingServices();
}

IntPtr VideoDriver_GetTexture(IntPtr videodriver, c8* name)
{
    return GetVideoFromIntPtr(videodriver)->getTexture(name);
}

int VideoDriver_GetFPS(IntPtr videodriver)
{
     return GetVideoFromIntPtr(videodriver)->getFPS();
}

void VideoDriver_MakeColorKeyTexture(IntPtr videodriver, IntPtr texture, M_POS2DS colorKeyPixelPos)
{
	GetVideoFromIntPtr(videodriver)->makeColorKeyTexture((ITexture*)texture, MU_POS2DS(colorKeyPixelPos));
}

void VideoDriver_MakeColorKeyTextureA(IntPtr videodriver, IntPtr texture, M_SCOLOR color)
{
	GetVideoFromIntPtr(videodriver)->makeColorKeyTexture((ITexture*)texture, MU_SCOLOR(color));
}

void VideoDriver_MakeNormalMapTexture(IntPtr videodriver, IntPtr texture, float amplitude)
{
	GetVideoFromIntPtr(videodriver)->makeNormalMapTexture((ITexture*)texture, amplitude);
}

void VideoDriver_ClearZBuffer(IntPtr videodriver)
{
	GetVideoFromIntPtr(videodriver)->clearZBuffer();
}

IntPtr VideoDriver_CreateImageFromFile(IntPtr videodriver, M_STRING filename)
{
	return GetVideoFromIntPtr(videodriver)->createImageFromFile(filename);
}

IntPtr VideoDriver_CreateRenderTargetTexture(IntPtr videodriver, M_DIM2DS size)
{
	return GetVideoFromIntPtr(videodriver)->createRenderTargetTexture(MU_DIM2DS(size));
}

void VideoDriver_Draw2DImage(IntPtr videodriver, IntPtr texture, M_POS2DS destPos, M_RECT sourceRect, M_RECT clipRect, M_SCOLOR color, bool useAlphaChannelOfTexture)
{
	GetVideoFromIntPtr(videodriver)->draw2DImage((ITexture*)texture, MU_POS2DS(destPos), MU_RECT(sourceRect), &MU_RECT(clipRect), MU_SCOLOR(color), useAlphaChannelOfTexture);
}

void VideoDriver_Draw2DImageA(IntPtr videodriver, IntPtr texture, M_POS2DS destPos)
{
	GetVideoFromIntPtr(videodriver)->draw2DImage((ITexture*)texture, MU_POS2DS(destPos));
}

void VideoDriver_Draw2DImageB(IntPtr videodriver, IntPtr texture, M_POS2DS destPos, M_RECT sourceRect, M_SCOLOR color, bool useAlphaChannelOfTexture)
{
	GetVideoFromIntPtr(videodriver)->draw2DImage((ITexture*)texture, MU_POS2DS(destPos), MU_RECT(sourceRect), 0, MU_SCOLOR(color), useAlphaChannelOfTexture);
}

void VideoDriver_Draw2DImageC(IntPtr videodriver, IntPtr texture, M_RECT destPos, M_RECT sourceRect, M_RECT clipRect, M_SCOLOR color1, M_SCOLOR color2, M_SCOLOR color3, M_SCOLOR color4, bool useAlphaChannelOfTexture)
{
	SColor *colors = new SColor[4];
	colors[0] = MU_SCOLOR(color1);
	colors[1] = MU_SCOLOR(color2);
	colors[2] = MU_SCOLOR(color3);
	colors[3] = MU_SCOLOR(color4);
	GetVideoFromIntPtr(videodriver)->draw2DImage((ITexture*)texture, MU_RECT(destPos), MU_RECT(sourceRect), &MU_RECT(clipRect), colors, useAlphaChannelOfTexture);
	delete[] colors;
}

void VideoDriver_Draw2DImageD(IntPtr videodriver, IntPtr texture, M_RECT destPos, M_RECT sourceRect, M_SCOLOR color1, M_SCOLOR color2, M_SCOLOR color3, M_SCOLOR color4, bool useAlphaChannelOfTexture)
{
	SColor *colors = new SColor[4];
	colors[0] = MU_SCOLOR(color1);
	colors[1] = MU_SCOLOR(color2);
	colors[2] = MU_SCOLOR(color3);
	colors[3] = MU_SCOLOR(color4);
	GetVideoFromIntPtr(videodriver)->draw2DImage((ITexture*)texture, MU_RECT(destPos), MU_RECT(sourceRect), 0, colors, useAlphaChannelOfTexture);
	delete[] colors;
}

void VideoDriver_Draw2DLine(IntPtr videodriver, M_POS2DS start, M_POS2DS end, M_SCOLOR color)
{
	GetVideoFromIntPtr(videodriver)->draw2DLine(MU_POS2DS(start), MU_POS2DS(end), MU_SCOLOR(color));
}

void VideoDriver_Draw2DPolygon(IntPtr videodriver, M_POS2DS center, float radius, M_SCOLOR color, int vertexCount)
{
	GetVideoFromIntPtr(videodriver)->draw2DPolygon(MU_POS2DS(center), radius, MU_SCOLOR(color), vertexCount);
}

void VideoDriver_Draw2DRectangle(IntPtr videodriver, M_RECT pos, M_SCOLOR colorLeftUp, M_SCOLOR colorRightUp, M_SCOLOR colorLeftDown, M_SCOLOR colorRightDown)
{
	GetVideoFromIntPtr(videodriver)->draw2DRectangle(MU_RECT(pos), MU_SCOLOR(colorLeftUp), MU_SCOLOR(colorRightUp), MU_SCOLOR(colorLeftDown), MU_SCOLOR(colorRightDown));
}

void VideoDriver_Draw3DBox(IntPtr videodriver, M_BOX3D box, M_SCOLOR color)
{
	GetVideoFromIntPtr(videodriver)->draw3DBox(MU_BOX3D(box), MU_SCOLOR(color));
}

void VideoDriver_Draw3DLine(IntPtr videodriver, M_VECT3DF start, M_VECT3DF end, M_SCOLOR color)
{
	GetVideoFromIntPtr(videodriver)->draw3DLine(MU_VECT3DF(start), MU_VECT3DF(end), MU_SCOLOR(color));
}

void VideoDriver_Draw3DTriangle(IntPtr videodriver, M_TRIANGLE3DF tri, M_SCOLOR color)
{
	GetVideoFromIntPtr(videodriver)->draw3DTriangle(MU_TRIANGLE3DF(tri), MU_SCOLOR(color));
}

void VideoDriver_GetScreenSize(IntPtr videodriver, M_DIM2DS size)
{
	UM_DIM2DS(GetVideoFromIntPtr(videodriver)->getScreenSize(), size);
}

void VideoDriver_DrawIndexedTriangleList(IntPtr videodriver, IntPtr *vertices, int vertexCount, unsigned short *indexList, int triangleCount)
{
	S3DVertex* list = new S3DVertex[vertexCount];
	for(int i = 0; i < vertexCount; i++)
		list[i] = *((S3DVertex*)vertices[i]);
	GetVideoFromIntPtr(videodriver)->drawIndexedTriangleList(list, vertexCount, indexList, triangleCount);
	delete[] list;
}

void VideoDriver_DrawIndexedTriangleListA(IntPtr videodriver, IntPtr *vertices, int vertexCount, unsigned short *indexList, int triangleCount)
{
	 S3DVertex2TCoords* list = new  S3DVertex2TCoords[vertexCount];
	for(int i = 0; i < vertexCount; i++)
		list[i] = *(( S3DVertex2TCoords*)vertices[i]);
	GetVideoFromIntPtr(videodriver)->drawIndexedTriangleList(list, vertexCount, indexList, triangleCount);
	delete[] list;
}

void VideoDriver_DrawIndexedTriangleFan(IntPtr videodriver, IntPtr *vertices, int vertexCount, unsigned short *indexList, int triangleCount)
{
	S3DVertex* list = new S3DVertex[vertexCount];
	for(int i = 0; i < vertexCount; i++)
		list[i] = *((S3DVertex*)vertices[i]);
	GetVideoFromIntPtr(videodriver)->drawIndexedTriangleFan(list, vertexCount, indexList, triangleCount);
	delete[] list;
}

void VideoDriver_DrawIndexedTriangleFanA(IntPtr videodriver, IntPtr *vertices, int vertexCount, unsigned short *indexList, int triangleCount)
{
	 S3DVertex2TCoords* list = new  S3DVertex2TCoords[vertexCount];
	for(int i = 0; i < vertexCount; i++)
		list[i] = *(( S3DVertex2TCoords*)vertices[i]);
	GetVideoFromIntPtr(videodriver)->drawIndexedTriangleFan(list, vertexCount, indexList, triangleCount);
	delete[] list;
}

bool VideoDriver_GetTextureCreationFlag(IntPtr videodriver, E_TEXTURE_CREATION_FLAG flag)
{
	_FIX_BOOL_MARSHAL_BUG(GetVideoFromIntPtr(videodriver)->getTextureCreationFlag(flag));
}

void VideoDriver_GetViewPort(IntPtr videodriver, M_RECT viewport)
{
	UM_RECT(GetVideoFromIntPtr(videodriver)->getViewPort(), viewport);
}
bool VideoDriver_QueryFeature(IntPtr videodriver, E_VIDEO_DRIVER_FEATURE feat)
{
	_FIX_BOOL_MARSHAL_BUG(GetVideoFromIntPtr(videodriver)->queryFeature(feat));
}
void VideoDriver_RemoveAllTextures(IntPtr videodriver)
{
	GetVideoFromIntPtr(videodriver)->removeAllTextures();
}
void VideoDriver_RemoveTexture(IntPtr videodriver, IntPtr texture)
{
	GetVideoFromIntPtr(videodriver)->removeTexture((ITexture*)texture);
}

void VideoDriver_GetTransform(IntPtr videodriver, E_TRANSFORMATION_STATE state, M_MAT4 mat)
{
	UM_MAT4(GetVideoFromIntPtr(videodriver)->getTransform(state), mat);
}
void VideoDriver_SetTransform(IntPtr videodriver, E_TRANSFORMATION_STATE state, M_MAT4 mat)
{
	GetVideoFromIntPtr(videodriver)->setTransform(state, MU_MAT4(mat));
}
void VideoDriver_SetAmbientLight(IntPtr videodriver, M_SCOLOR ambient)
{
	GetVideoFromIntPtr(videodriver)->setAmbientLight(MU_SCOLOR(ambient));
}
void VideoDriver_SetFog(IntPtr videodriver, M_SCOLOR color, bool linear, float start, float end, float density, bool pixel, bool range)
{
	GetVideoFromIntPtr(videodriver)->setFog(MU_SCOLOR(color), linear, start, end, density, pixel, range);
}
void VideoDriver_SetMaterial(IntPtr videodriver, IntPtr material)
{
	GetVideoFromIntPtr(videodriver)->setMaterial(*((SMaterial*)material));
}
void VideoDriver_SetRenderTarget(IntPtr videodriver, IntPtr texture, bool cBB, bool cZB, M_SCOLOR color)
{
	GetVideoFromIntPtr(videodriver)->setRenderTarget((ITexture*)texture, cBB, cZB, MU_SCOLOR(color));
}
void VideoDriver_SetTextureFlag(IntPtr videodriver, E_TEXTURE_CREATION_FLAG flag, bool enabled)
{
	GetVideoFromIntPtr(videodriver)->setTextureCreationFlag(flag, enabled);
}
void VideoDriver_SetViewPort(IntPtr videodriver, M_RECT viewport)
{
	GetVideoFromIntPtr(videodriver)->setViewPort(MU_RECT(viewport));
}

void VideoDriver_DeleteAllDynamicLights(IntPtr videodriver)
{
   GetVideoFromIntPtr(videodriver)->deleteAllDynamicLights();
} 

IntPtr VideoDriver_CreateScreenshot(IntPtr videodriver)
{
	return GetVideoFromIntPtr(videodriver)->createScreenShot();
}

void VideoDriver_WriteImageToFile(IntPtr videodriver, IntPtr image, M_STRING filename)
{
	GetVideoFromIntPtr(videodriver)->writeImageToFile((IImage*)image, filename);
}

int VideoDriver_GetTextureCount(IntPtr videodriver)
{
	return GetVideoFromIntPtr(videodriver)->getTextureCount();
}

IntPtr VideoDriver_GetTextureByIndex(IntPtr videodriver, int index)
{
	return GetVideoFromIntPtr(videodriver)->getTextureByIndex(index);
}

int VideoDriver_GetPrimitiveCountDrawn(IntPtr videodriver)
{
	return GetVideoFromIntPtr(videodriver)->getPrimitiveCountDrawn();
}