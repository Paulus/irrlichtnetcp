#include "mesh.h"

IntPtr Mesh_Create(void)
{
	return new SMesh();
}
void Mesh_AddMeshBuffer(IntPtr mesh, IntPtr meshbuf)
{
	((SMesh*)mesh)->addMeshBuffer((IMeshBuffer*)meshbuf);
}
void Mesh_GetBoundingBox(IntPtr mesh, M_BOX3D box)
{
    UM_BOX3D(((IMesh*)mesh)->getBoundingBox(), box);
}

void Mesh_SetMaterialFlag(IntPtr mesh, E_MATERIAL_FLAG flag, bool newValue)
{
    ((IMesh*)mesh)->setMaterialFlag(flag, newValue);
}

int Mesh_GetMeshBufferCount(IntPtr mesh)
{
	return ((IMesh*)mesh)->getMeshBufferCount();
}

IntPtr Mesh_GetMeshBuffer(IntPtr mesh, int nr)
{
	return ((IMesh*)mesh)->getMeshBuffer(nr);
}

void AnimatedMesh_GetBoundingBox(IntPtr mesh, M_BOX3D box)
{
    UM_BOX3D(((IAnimatedMesh*)mesh)->getBoundingBox(), box);
}
IntPtr AnimatedMesh_GetMesh(IntPtr mesh, int frame, int detailLevel, int startFrameloop, int endFrameloop)
{
    return ((IAnimatedMesh*)mesh)->getMesh(frame, detailLevel, startFrameloop, endFrameloop);
}
E_ANIMATED_MESH_TYPE AnimatedMesh_GetMeshType(IntPtr mesh)
{
    return ((IAnimatedMesh*)mesh)->getMeshType();
}

void AnimatedMesh_GetFrameLoopMD2 (IntPtr mesh, EMD2_ANIMATION_TYPE l, int* outBegin, int* outEnd, int* outFPS)
{
    int b;
    int en;
    int fps;
    ((IAnimatedMeshMD2 *)mesh)->getFrameLoop(l, b, en, fps);
    *outBegin = b;
    *outEnd = en;
    *outFPS = fps;
}

void AnimatedMesh_GetFrameLoopMD2a (IntPtr mesh, M_STRING name, int *outBegin, int *outEnd, int *outFPS)
{
    int b;
    int en;
    int fps;
    ((IAnimatedMeshMD2 *)mesh)->getFrameLoop(UM_STRING(name), b, en, fps);
    *outBegin = b;
    *outEnd = en;
    *outFPS = fps;
}

int AnimationMesh_GetAnimationCountMD2(IntPtr mesh)
{
    return ((IAnimatedMeshMD2 *)mesh)->getAnimationCount();
}

M_STRING AnimationMesh_GetAnimationNameMD2(IntPtr mesh, int nr)
{
    return UM_STRING(((IAnimatedMeshMD2 *)mesh)->getAnimationName(nr));
}


IMeshBuffer* GetMBForIntPtr(IntPtr mb)
{
	return ((IMeshBuffer*)mb);
}

IntPtr MeshBuffer_Create(int type)
{
	if(type == 0)
		return new SMeshBuffer();
	else if(type == 1)
		return new SMeshBufferLightMap();
	return new SMeshBufferTangents();
}

void MeshBuffer_GetBoundingBox(IntPtr meshb, M_BOX3D bb)
{
	UM_BOX3D(GetMBForIntPtr(meshb)->getBoundingBox(), bb);
}

void MeshBuffer_SetBoundingBox(IntPtr meshb, M_BOX3D bb)
{
	GetMBForIntPtr(meshb)->setBoundingBox(MU_BOX3D(bb));
}

int MeshBuffer_GetIndexCount(IntPtr meshb)
{
	return GetMBForIntPtr(meshb)->getIndexCount();
}

void MeshBuffer_GetIndices(IntPtr meshb, unsigned short* indices)
{
	int count = GetMBForIntPtr(meshb)->getIndexCount();
	for(int i = 0; i < count; i++)
		indices[i] = GetMBForIntPtr(meshb)->getIndices()[i];
}

void MeshBuffer_SetIndices(IntPtr meshb, unsigned short* indices, int count)
{
		switch(MeshBuffer_GetVertexType(meshb))
		{
			case EVT_STANDARD:
				((SMeshBuffer*)meshb)->Indices.set_pointer(indices, count);
				break;
			case EVT_2TCOORDS:
				((SMeshBufferLightMap*)meshb)->Indices.set_pointer(indices, count);
				break;
			case EVT_TANGENTS:
				((SMeshBufferTangents*)meshb)->Indices.set_pointer(indices, count);
				break;
		}
}

unsigned short MeshBuffer_GetIndex(IntPtr meshb, unsigned int nr)
{
	return GetMBForIntPtr(meshb)->getIndices()[nr];
}

void MeshBuffer_SetIndex(IntPtr meshb, unsigned int nr, unsigned short val)
{
	if(GetMBForIntPtr(meshb)->getIndexCount() > nr)
		GetMBForIntPtr(meshb)->getIndices()[nr] = val;
	else
	{
		switch(MeshBuffer_GetVertexType(meshb))
		{
			case EVT_STANDARD:
				((SMeshBuffer*)meshb)->Indices.push_back(val);
				MeshBuffer_SetIndex(meshb, nr, val);
				break;
			case EVT_2TCOORDS:
				((SMeshBufferLightMap*)meshb)->Indices.push_back(val);
				MeshBuffer_SetIndex(meshb, nr, val);
				break;
			case EVT_TANGENTS:
				((SMeshBufferTangents*)meshb)->Indices.push_back(val);
				MeshBuffer_SetIndex(meshb, nr, val);
				break;
		}
	}
}

IntPtr MeshBuffer_GetMaterial(IntPtr meshb)
{
	return &GetMBForIntPtr(meshb)->getMaterial();
}

void MeshBuffer_SetMaterial(IntPtr meshb, IntPtr material)
{
	GetMBForIntPtr(meshb)->getMaterial() = *((SMaterial*)material);
}

int MeshBuffer_GetVertexCount(IntPtr meshb)
{
	return GetMBForIntPtr(meshb)->getVertexCount();
}

E_VERTEX_TYPE MeshBuffer_GetVertexType(IntPtr meshb)
{
	return GetMBForIntPtr(meshb)->getVertexType();
}

IntPtr MeshBuffer_GetVertex(IntPtr meshb, unsigned int nr)
{
	return &(((S3DVertex*)GetMBForIntPtr(meshb)->getVertices())[nr]);
}

void MeshBuffer_SetVertex(IntPtr meshb, unsigned int nr, IntPtr vert)
{
	SMeshBuffer *mb = ((SMeshBuffer*)meshb);
	if(nr >= mb->getVertexCount())
	{
		mb->Vertices.push_back(*((S3DVertex*)vert));
		MeshBuffer_SetVertex(meshb, nr, vert);
	}
	else
		(((S3DVertex*)(mb->getVertices()))[nr]) = *((S3DVertex*)vert);
}

IntPtr MeshBuffer_GetVertex2T(IntPtr meshb, unsigned int nr)
{
	return &(((S3DVertex2TCoords*)GetMBForIntPtr(meshb)->getVertices())[nr]);
}

void MeshBuffer_SetVertex2T(IntPtr meshb, unsigned int nr, IntPtr vert)
{
	SMeshBufferLightMap *mb = ((SMeshBufferLightMap*)meshb);
	if(nr >= mb->getVertexCount())
	{
		mb->Vertices.push_back(*((S3DVertex2TCoords*)vert));
		MeshBuffer_SetVertex2T(meshb, nr, vert);
	}
	else
		(((S3DVertex2TCoords*)(mb->getVertices()))[nr]) = *((S3DVertex2TCoords*)vert);
}
