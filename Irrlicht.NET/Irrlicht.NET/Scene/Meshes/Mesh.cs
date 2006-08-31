using System;
using System.Runtime.InteropServices;

namespace IrrlichtNETCP
{
	public class Mesh : NativeElement
	{
		public Mesh(IntPtr raw) : base(raw)
		{
		}
		public Box3D BoundingBox
		{
			get
			{
				float[] box = new float[6];
				Mesh_GetBoundingBox(_raw, box);
				return Box3D.FromUnmanaged(box);
			}
		}
		
		public void SetMaterialFlag(MaterialFlag flag, bool newValue)
		{
			Mesh_SetMaterialFlag(_raw, flag, newValue);
		}

        public int MeshBufferCount
        {
            get
            {
                return Mesh_GetMeshBufferCount(_raw);
            }
        }

        public MeshBuffer GetMeshBuffer(int nr)
        {
            return (MeshBuffer)NativeElement.GetObject(Mesh_GetMeshBuffer(_raw, nr), typeof(MeshBuffer));
        }
		
		#region .NET Wrapper Native Code
		[DllImport(Native.Dll)]
        static extern void Mesh_GetBoundingBox(IntPtr mesh, [MarshalAs(UnmanagedType.LPArray)] float[] box);
		
		[DllImport(Native.Dll)]
		static extern void Mesh_SetMaterialFlag(IntPtr mesh, MaterialFlag flag, bool newValue);

        [DllImport(Native.Dll)]
		static extern int Mesh_GetMeshBufferCount(IntPtr mesh);

        [DllImport(Native.Dll)]
        static extern IntPtr Mesh_GetMeshBuffer(IntPtr mesh, int nr);
		#endregion
	}
	
}
