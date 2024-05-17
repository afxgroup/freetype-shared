#include <stdarg.h>
#include <exec/exec.h>
#include <proto/exec.h>
#include <proto/freetype.h>

#include <freetype/freetype.h>
#include <freetype/ftadvanc.h>
#include <freetype/ftbdf.h>
#include <freetype/ftbbox.h>
#include <freetype/ftbitmap.h>
#include <freetype/ftbzip2.h>
#include <freetype/ftcache.h>
#include <freetype/ftcid.h>
#include <freetype/ftcolor.h>
#include <freetype/ftfntfmt.h>
#include <freetype/ftgasp.h>
#include <freetype/ftgxval.h>
#include <freetype/ftgzip.h>
#include <freetype/ftlcdfil.h>
#include <freetype/ftlist.h>
#include <freetype/ftlogging.h>
#include <freetype/ftmm.h>
#include <freetype/ftmodapi.h>
#include <freetype/ftoutln.h>
#include <freetype/ftsnames.h>
#include <freetype/ftstroke.h>
#include <freetype/fttrigon.h>
#include <freetype/ftwinfnt.h>
#include <freetype/t1tables.h>
#include <freetype/tttables.h>

uint32 _impl_Obtain(struct FreetypeIFace *Self)
{
	uint32 res;
	__asm__ __volatile__(
		"1:	lwarx	%0,0,%1\n"
		"addic	%0,%0,1\n"
		"stwcx.	%0,0,%1\n"
		"bne-	1b"
		: "=&r"(res)
		: "r"(&Self->Data.RefCount)
		: "cc", "memory");

	return res;
}

uint32 _impl_Release(struct FreetypeIFace *Self)
{
	uint32 res;
	__asm__ __volatile__(
		"1:	lwarx	%0,0,%1\n"
		"addic	%0,%0,-1\n"
		"stwcx.	%0,0,%1\n"
		"bne-	1b"
		: "=&r"(res)
		: "r"(&Self->Data.RefCount)
		: "cc", "memory");

	return res;
}

FT_Error _impl_FT_Init_FreeType(struct FreetypeIFace *Self, FT_Library * alibrary) {
	return FT_Init_FreeType(alibrary);
}

FT_Error _impl_FT_Done_FreeType(struct FreetypeIFace *Self, FT_Library library) {
	return FT_Done_FreeType(library);
}

FT_Error _impl_FT_New_Face(struct FreetypeIFace *Self, FT_Library library, const char* filepathname, FT_Long face_index, FT_Face * aface) {
	return FT_New_Face(library,filepathname,face_index,aface);
}

FT_Error _impl_FT_New_Memory_Face(struct FreetypeIFace *Self, FT_Library library, const FT_Byte* file_base, FT_Long file_size, FT_Long face_index, FT_Face * aface) {
	return FT_New_Memory_Face(library,file_base,file_size,face_index,aface);
}

FT_Error _impl_FT_Open_Face(struct FreetypeIFace *Self, FT_Library library, const FT_Open_Args* args, FT_Long face_index, FT_Face * aface) {
	return FT_Open_Face(library,args,face_index,aface);
}

FT_Error _impl_FT_Attach_File(struct FreetypeIFace *Self, FT_Face face, const char* filepathname) {
	return FT_Attach_File(face,filepathname);
}

FT_Error _impl_FT_Attach_Stream(struct FreetypeIFace *Self, FT_Face face, const FT_Open_Args* parameters) {
	return FT_Attach_Stream(face,parameters);
}

FT_Error _impl_FT_Reference_Face(struct FreetypeIFace *Self, FT_Face face) {
	return FT_Reference_Face(face);
}

FT_Error _impl_FT_Done_Face(struct FreetypeIFace *Self, FT_Face face) {
	return FT_Done_Face(face);
}

FT_Error _impl_FT_Select_Size(struct FreetypeIFace *Self, FT_Face face, FT_Int strike_index) {
	return FT_Select_Size(face,strike_index);
}

FT_Error _impl_FT_Request_Size(struct FreetypeIFace *Self, FT_Face face, FT_Size_Request req) {
	return FT_Request_Size(face,req);
}

FT_Error _impl_FT_Set_Char_Size(struct FreetypeIFace *Self, FT_Face face, FT_F26Dot6 char_width, FT_F26Dot6 char_height, FT_UInt horz_resolution, FT_UInt vert_resolution) {
	return FT_Set_Char_Size(face,char_width,char_height,horz_resolution,vert_resolution);
}

FT_Error _impl_FT_Set_Pixel_Sizes(struct FreetypeIFace *Self, FT_Face face, FT_UInt pixel_width, FT_UInt pixel_height) {
	return FT_Set_Pixel_Sizes(face,pixel_width,pixel_height);
}

FT_Error _impl_FT_Load_Glyph(struct FreetypeIFace *Self, FT_Face face, FT_UInt glyph_index, FT_Int32 load_flags) {
	return FT_Load_Glyph(face,glyph_index,load_flags);
}

FT_Error _impl_FT_Load_Char(struct FreetypeIFace *Self, FT_Face face, FT_ULong char_code, FT_Int32 load_flags) {
	return FT_Load_Char(face,char_code,load_flags);
}

void _impl_FT_Set_Transform(struct FreetypeIFace *Self, FT_Face face, FT_Matrix* matrix, FT_Vector* delta) {
	FT_Set_Transform(face,matrix,delta);
}

void _impl_FT_Get_Transform(struct FreetypeIFace *Self, FT_Face face, FT_Matrix* matrix, FT_Vector* delta) {
	FT_Get_Transform(face,matrix,delta);
}

FT_Error _impl_FT_Render_Glyph(struct FreetypeIFace *Self, FT_GlyphSlot slot, FT_Render_Mode render_mode) {
	return FT_Render_Glyph(slot,render_mode);
}

FT_Error _impl_FT_Get_Kerning(struct FreetypeIFace *Self, FT_Face face, FT_UInt left_glyph, FT_UInt right_glyph, FT_UInt kern_mode, FT_Vector * akerning) {
	return FT_Get_Kerning(face,left_glyph,right_glyph,kern_mode,akerning);
}

FT_Error _impl_FT_Get_Track_Kerning(struct FreetypeIFace *Self, FT_Face face, FT_Fixed point_size, FT_Int degree, FT_Fixed* akerning) {
	return FT_Get_Track_Kerning(face,point_size,degree,akerning);
}

FT_Error _impl_FT_Select_Charmap(struct FreetypeIFace *Self, FT_Face face, FT_Encoding encoding) {
	return FT_Select_Charmap(face,encoding);
}

FT_Error _impl_FT_Set_Charmap(struct FreetypeIFace *Self, FT_Face face, FT_CharMap charmap) {
	return FT_Set_Charmap(face,charmap);
}

FT_Int _impl_FT_Get_Charmap_Index(struct FreetypeIFace *Self, FT_CharMap charmap) {
	return FT_Get_Charmap_Index(charmap);
}

FT_UInt _impl_FT_Get_Char_Index(struct FreetypeIFace *Self, FT_Face face, FT_ULong charcode) {
	return FT_Get_Char_Index(face,charcode);
}

FT_ULong _impl_FT_Get_First_Char(struct FreetypeIFace *Self, FT_Face face, FT_UInt * agindex) {
	return FT_Get_First_Char(face,agindex);
}

FT_ULong _impl_FT_Get_Next_Char(struct FreetypeIFace *Self, FT_Face face, FT_ULong char_code, FT_UInt * agindex) {
	return FT_Get_Next_Char(face,char_code,agindex);
}

FT_Error _impl_FT_Face_Properties(struct FreetypeIFace *Self, FT_Face face, FT_UInt num_properties, FT_Parameter* properties) {
	return FT_Face_Properties(face,num_properties,properties);
}

FT_UInt _impl_FT_Get_Name_Index(struct FreetypeIFace *Self, FT_Face face, const FT_String* glyph_name) {
	return FT_Get_Name_Index(face,glyph_name);
}

FT_Error _impl_FT_Get_Glyph_Name(struct FreetypeIFace *Self, FT_Face face, FT_UInt glyph_index, FT_Pointer buffer, FT_UInt buffer_max) {
	return FT_Get_Glyph_Name(face,glyph_index,buffer,buffer_max);
}

const char* _impl_FT_Get_Postscript_Name(struct FreetypeIFace *Self, FT_Face face) {
	return FT_Get_Postscript_Name(face);
}

FT_Error _impl_FT_Get_SubGlyph_Info(struct FreetypeIFace *Self, FT_GlyphSlot glyph, FT_UInt sub_index, FT_Int * p_index, FT_UInt * p_flags, FT_Int * p_arg1, FT_Int * p_arg2, FT_Matrix * p_transform) {
	return FT_Get_SubGlyph_Info(glyph,sub_index,p_index,p_flags,p_arg1,p_arg2,p_transform);
}

FT_UShort _impl_FT_Get_FSType_Flags(struct FreetypeIFace *Self, FT_Face face) {
	return FT_Get_FSType_Flags(face);
}

FT_UInt _impl_FT_Face_GetCharVariantIndex(struct FreetypeIFace *Self, FT_Face face, FT_ULong charcode, FT_ULong variantSelector) {
	return FT_Face_GetCharVariantIndex(face,charcode,variantSelector);
}

FT_Int _impl_FT_Face_GetCharVariantIsDefault(struct FreetypeIFace *Self, FT_Face face, FT_ULong charcode, FT_ULong variantSelector) {
	return FT_Face_GetCharVariantIsDefault(face,charcode,variantSelector);
}

FT_UInt32* _impl_FT_Face_GetVariantSelectors(struct FreetypeIFace *Self, FT_Face face) {
	return FT_Face_GetVariantSelectors(face);
}

FT_UInt32* _impl_FT_Face_GetVariantsOfChar(struct FreetypeIFace *Self, FT_Face face, FT_ULong charcode) {
	return FT_Face_GetVariantsOfChar(face,charcode);
}

FT_UInt32* _impl_FT_Face_GetCharsOfVariant(struct FreetypeIFace *Self, FT_Face face, FT_ULong variantSelector) {
	return FT_Face_GetCharsOfVariant(face,variantSelector);
}

FT_Long _impl_FT_MulDiv(struct FreetypeIFace *Self, FT_Long a, FT_Long b, FT_Long c) {
	return FT_MulDiv(a,b,c);
}

FT_Long _impl_FT_MulFix(struct FreetypeIFace *Self, FT_Long a, FT_Long b) {
	return FT_MulFix(a,b);
}

FT_Long _impl_FT_DivFix(struct FreetypeIFace *Self, FT_Long a, FT_Long b) {
	return FT_DivFix(a,b);
}

FT_Fixed _impl_FT_RoundFix(struct FreetypeIFace *Self, FT_Fixed a) {
	return FT_RoundFix(a);
}

FT_Fixed _impl_FT_CeilFix(struct FreetypeIFace *Self, FT_Fixed a) {
	return FT_CeilFix(a);
}

FT_Fixed _impl_FT_FloorFix(struct FreetypeIFace *Self, FT_Fixed a) {
	return FT_FloorFix(a);
}

void _impl_FT_Vector_Transform(struct FreetypeIFace *Self, FT_Vector* vector, const FT_Matrix* matrix) {
	FT_Vector_Transform(vector,matrix);
}

void _impl_FT_Library_Version(struct FreetypeIFace *Self, FT_Library library, FT_Int * amajor, FT_Int * aminor, FT_Int * apatch) {
	FT_Library_Version(library,amajor,aminor,apatch);
}

FT_Bool _impl_FT_Face_CheckTrueTypePatents(struct FreetypeIFace *Self, FT_Face face) {
	return FT_Face_CheckTrueTypePatents(face);
}

FT_Bool _impl_FT_Face_SetUnpatentedHinting(struct FreetypeIFace *Self, FT_Face face, FT_Bool value) {
	return FT_Face_SetUnpatentedHinting(face,value);
}

FT_Error _impl_FT_Get_Advance(struct FreetypeIFace *Self, FT_Face face, FT_UInt gindex, FT_Int32 load_flags, FT_Fixed * padvance) {
	return FT_Get_Advance(face,gindex,load_flags,padvance);
}

FT_Error _impl_FT_Get_Advances(struct FreetypeIFace *Self, FT_Face face, FT_UInt start, FT_UInt count, FT_Int32 load_flags, FT_Fixed * padvances) {
	return FT_Get_Advances(face,start,count,load_flags,padvances);
}

FT_Error _impl_FT_Outline_Get_BBox(struct FreetypeIFace *Self, FT_Outline* outline, FT_BBox * abbox) {
	return FT_Outline_Get_BBox(outline,abbox);
}

FT_Error _impl_FT_Get_BDF_Charset_ID(struct FreetypeIFace *Self, FT_Face face, const char* * acharset_encoding, const char* * acharset_registry) {
	return FT_Get_BDF_Charset_ID(face,acharset_encoding,acharset_registry);
}

FT_Error _impl_FT_Get_BDF_Property(struct FreetypeIFace *Self, FT_Face face, const char* prop_name, BDF_PropertyRec * aproperty) {
	return FT_Get_BDF_Property(face,prop_name,aproperty);
}

void _impl_FT_Bitmap_Init(struct FreetypeIFace *Self, FT_Bitmap * abitmap) {
	FT_Bitmap_Init(abitmap);
}

void _impl_FT_Bitmap_New(struct FreetypeIFace *Self, FT_Bitmap * abitmap) {
	FT_Bitmap_New(abitmap);
}

FT_Error _impl_FT_Bitmap_Copy(struct FreetypeIFace *Self, FT_Library library, const FT_Bitmap * source, FT_Bitmap * target) {
	return FT_Bitmap_Copy(library,source,target);
}

FT_Error _impl_FT_Bitmap_Embolden(struct FreetypeIFace *Self, FT_Library library, FT_Bitmap* bitmap, FT_Pos xStrength, FT_Pos yStrength) {
	return FT_Bitmap_Embolden(library,bitmap,xStrength,yStrength);
}

FT_Error _impl_FT_Bitmap_Convert(struct FreetypeIFace *Self, FT_Library library, const FT_Bitmap * source, FT_Bitmap * target, FT_Int alignment) {
	return FT_Bitmap_Convert(library,source,target,alignment);
}

FT_Error _impl_FT_Bitmap_Blend(struct FreetypeIFace *Self, FT_Library library, const FT_Bitmap* source, const FT_Vector source_offset, FT_Bitmap* target, FT_Vector * atarget_offset, FT_Color color) {
	return FT_Bitmap_Blend(library,source,source_offset,target,atarget_offset,color);
}

FT_Error _impl_FT_GlyphSlot_Own_Bitmap(struct FreetypeIFace *Self, FT_GlyphSlot slot) {
	return FT_GlyphSlot_Own_Bitmap(slot);
}

FT_Error _impl_FT_Bitmap_Done(struct FreetypeIFace *Self, FT_Library library, FT_Bitmap * bitmap) {
	return FT_Bitmap_Done(library,bitmap);
}

FT_Error _impl_FT_Stream_OpenBzip2(struct FreetypeIFace *Self, FT_Stream stream, FT_Stream source) {
	return FT_Stream_OpenBzip2(stream,source);
}

FT_Error _impl_FTC_Manager_New(struct FreetypeIFace *Self, FT_Library library, FT_UInt max_faces, FT_UInt max_sizes, FT_ULong max_bytes, FTC_Face_Requester requester, FT_Pointer req_data, FTC_Manager * amanager) {
	return FTC_Manager_New(library,max_faces,max_sizes,max_bytes,requester,req_data,amanager);
}

void _impl_FTC_Manager_Reset(struct FreetypeIFace *Self, FTC_Manager manager) {
	FTC_Manager_Reset(manager);
}

void _impl_FTC_Manager_Done(struct FreetypeIFace *Self, FTC_Manager manager) {
	FTC_Manager_Done(manager);
}

FT_Error _impl_FTC_Manager_LookupFace(struct FreetypeIFace *Self, FTC_Manager manager, FTC_FaceID face_id, FT_Face * aface) {
	return FTC_Manager_LookupFace(manager,face_id,aface);
}

FT_Error _impl_FTC_Manager_LookupSize(struct FreetypeIFace *Self, FTC_Manager manager, FTC_Scaler scaler, FT_Size * asize) {
	return FTC_Manager_LookupSize(manager,scaler,asize);
}

void _impl_FTC_Node_Unref(struct FreetypeIFace *Self, FTC_Node node, FTC_Manager manager) {
	FTC_Node_Unref(node,manager);
}

void _impl_FTC_Manager_RemoveFaceID(struct FreetypeIFace *Self, FTC_Manager manager, FTC_FaceID face_id) {
	FTC_Manager_RemoveFaceID(manager,face_id);
}

FT_Error _impl_FTC_CMapCache_New(struct FreetypeIFace *Self, FTC_Manager manager, FTC_CMapCache * acache) {
	return FTC_CMapCache_New(manager,acache);
}

FT_UInt _impl_FTC_CMapCache_Lookup(struct FreetypeIFace *Self, FTC_CMapCache cache, FTC_FaceID face_id, FT_Int cmap_index, FT_UInt32 char_code) {
	return FTC_CMapCache_Lookup(cache,face_id,cmap_index,char_code);
}

FT_Error _impl_FTC_ImageCache_New(struct FreetypeIFace *Self, FTC_Manager manager, FTC_ImageCache * acache) {
	return FTC_ImageCache_New(manager,acache);
}

FT_Error _impl_FTC_ImageCache_Lookup(struct FreetypeIFace *Self, FTC_ImageCache cache, FTC_ImageType type, FT_UInt gindex, FT_Glyph * aglyph, FTC_Node * anode) {
	return FTC_ImageCache_Lookup(cache,type,gindex,aglyph,anode);
}

FT_Error _impl_FTC_ImageCache_LookupScaler(struct FreetypeIFace *Self, FTC_ImageCache cache, FTC_Scaler scaler, FT_ULong load_flags, FT_UInt gindex, FT_Glyph * aglyph, FTC_Node * anode) {
	return FTC_ImageCache_LookupScaler(cache,scaler,load_flags,gindex,aglyph,anode);
}

FT_Error _impl_FTC_SBitCache_New(struct FreetypeIFace *Self, FTC_Manager manager, FTC_SBitCache * acache) {
	return FTC_SBitCache_New(manager,acache);
}

FT_Error _impl_FTC_SBitCache_Lookup(struct FreetypeIFace *Self, FTC_SBitCache cache, FTC_ImageType type, FT_UInt gindex, FTC_SBit * sbit, FTC_Node * anode) {
	return FTC_SBitCache_Lookup(cache,type,gindex,sbit,anode);
}

FT_Error _impl_FTC_SBitCache_LookupScaler(struct FreetypeIFace *Self, FTC_SBitCache cache, FTC_Scaler scaler, FT_ULong load_flags, FT_UInt gindex, FTC_SBit * sbit, FTC_Node * anode) {
	return FTC_SBitCache_LookupScaler(cache,scaler,load_flags,gindex,sbit,anode);
}

FT_Error _impl_FT_Get_CID_Registry_Ordering_Supplement(struct FreetypeIFace *Self, FT_Face face, const char* * registry, const char* * ordering, FT_Int * supplement) {
	return FT_Get_CID_Registry_Ordering_Supplement(face,registry,ordering,supplement);
}

FT_Error _impl_FT_Get_CID_Is_Internally_CID_Keyed(struct FreetypeIFace *Self, FT_Face face, FT_Bool * is_cid) {
	return FT_Get_CID_Is_Internally_CID_Keyed(face,is_cid);
}

FT_Error _impl_FT_Get_CID_From_Glyph_Index(struct FreetypeIFace *Self, FT_Face face, FT_UInt glyph_index, FT_UInt * cid) {
	return FT_Get_CID_From_Glyph_Index(face,glyph_index,cid);
}

FT_Error _impl_FT_Palette_Data_Get(struct FreetypeIFace *Self, FT_Face face, FT_Palette_Data * apalette) {
	return FT_Palette_Data_Get(face,apalette);
}

FT_Error _impl_FT_Palette_Select(struct FreetypeIFace *Self, FT_Face face, FT_UShort palette_index, FT_Color* * apalette) {
	return FT_Palette_Select(face,palette_index,apalette);
}

FT_Error _impl_FT_Palette_Set_Foreground_Color(struct FreetypeIFace *Self, FT_Face face, FT_Color foreground_color) {
	return FT_Palette_Set_Foreground_Color(face,foreground_color);
}

FT_Bool _impl_FT_Get_Color_Glyph_Layer(struct FreetypeIFace *Self, FT_Face face, FT_UInt base_glyph, FT_UInt * aglyph_index, FT_UInt * acolor_index, FT_LayerIterator* iterator) {
	return FT_Get_Color_Glyph_Layer(face,base_glyph,aglyph_index,acolor_index,iterator);
}

FT_Bool _impl_FT_Get_Color_Glyph_Paint(struct FreetypeIFace *Self, FT_Face face, FT_UInt base_glyph, FT_Color_Root_Transform root_transform, FT_OpaquePaint* paint) {
	return FT_Get_Color_Glyph_Paint(face,base_glyph,root_transform,paint);
}

FT_Bool _impl_FT_Get_Color_Glyph_ClipBox(struct FreetypeIFace *Self, FT_Face face, FT_UInt base_glyph, FT_ClipBox* clip_box) {
	return FT_Get_Color_Glyph_ClipBox(face,base_glyph,clip_box);
}

FT_Bool _impl_FT_Get_Paint_Layers(struct FreetypeIFace *Self, FT_Face face, FT_LayerIterator* iterator, FT_OpaquePaint* paint) {
	return FT_Get_Paint_Layers(face,iterator,paint);
}

FT_Bool _impl_FT_Get_Colorline_Stops(struct FreetypeIFace *Self, FT_Face face, FT_ColorStop* color_stop, FT_ColorStopIterator* iterator) {
	return FT_Get_Colorline_Stops(face,color_stop,iterator);
}

FT_Bool _impl_FT_Get_Paint(struct FreetypeIFace *Self, FT_Face face, FT_OpaquePaint opaque_paint, FT_COLR_Paint* paint) {
	return FT_Get_Paint(face,opaque_paint,paint);
}

const char* _impl_FT_Error_String(struct FreetypeIFace *Self, FT_Error error_code) {
	return FT_Error_String(error_code);
}

const char* _impl_FT_Get_Font_Format(struct FreetypeIFace *Self, FT_Face face) {
	return FT_Get_Font_Format(face);
}

const char* _impl_FT_Get_X11_Font_Format(struct FreetypeIFace *Self, FT_Face face) {
	return FT_Get_X11_Font_Format(face);
}

FT_Int _impl_FT_Get_Gasp(struct FreetypeIFace *Self, FT_Face face, FT_UInt ppem) {
	return FT_Get_Gasp(face,ppem);
}

FT_Error _impl_FT_New_Glyph(struct FreetypeIFace *Self, FT_Library library, FT_Glyph_Format format, FT_Glyph * aglyph) {
	return FT_New_Glyph(library,format,aglyph);
}

FT_Error _impl_FT_Get_Glyph(struct FreetypeIFace *Self, FT_GlyphSlot slot, FT_Glyph * aglyph) {
	return FT_Get_Glyph(slot,aglyph);
}

FT_Error _impl_FT_Glyph_Copy(struct FreetypeIFace *Self, FT_Glyph source, FT_Glyph * target) {
	return FT_Glyph_Copy(source,target);
}

FT_Error _impl_FT_Glyph_Transform(struct FreetypeIFace *Self, FT_Glyph glyph, const FT_Matrix* matrix, const FT_Vector* delta) {
	return FT_Glyph_Transform(glyph,matrix,delta);
}

void _impl_FT_Glyph_Get_CBox(struct FreetypeIFace *Self, FT_Glyph glyph, FT_UInt bbox_mode, FT_BBox * acbox) {
	FT_Glyph_Get_CBox(glyph,bbox_mode,acbox);
}

FT_Error _impl_FT_Glyph_To_Bitmap(struct FreetypeIFace *Self, FT_Glyph* the_glyph, FT_Render_Mode render_mode, const FT_Vector* origin, FT_Bool destroy) {
	return FT_Glyph_To_Bitmap(the_glyph,render_mode,origin,destroy);
}

void _impl_FT_Done_Glyph(struct FreetypeIFace *Self, FT_Glyph glyph) {
	FT_Done_Glyph(glyph);
}

void _impl_FT_Matrix_Multiply(struct FreetypeIFace *Self, const FT_Matrix* a, FT_Matrix* b) {
	FT_Matrix_Multiply(a,b);
}

FT_Error _impl_FT_Matrix_Invert(struct FreetypeIFace *Self, FT_Matrix* matrix) {
	return FT_Matrix_Invert(matrix);
}

FT_Error _impl_FT_TrueTypeGX_Validate(struct FreetypeIFace *Self, FT_Face face, FT_UInt validation_flags, FT_Bytes tables[FT_VALIDATE_GX_LENGTH], FT_UInt table_length) {
	return FT_TrueTypeGX_Validate(face,validation_flags,tables[FT_VALIDATE_GX_LENGTH],table_length);
}

void _impl_FT_TrueTypeGX_Free(struct FreetypeIFace *Self, FT_Face face, FT_Bytes table) {
	FT_TrueTypeGX_Free(face,table);
}

FT_Error _impl_FT_ClassicKern_Validate(struct FreetypeIFace *Self, FT_Face face, FT_UInt validation_flags, FT_Bytes * ckern_table) {
	return FT_ClassicKern_Validate(face,validation_flags,ckern_table);
}

void _impl_FT_ClassicKern_Free(struct FreetypeIFace *Self, FT_Face face, FT_Bytes table) {
	FT_ClassicKern_Free(face,table);
}

FT_Error _impl_FT_Stream_OpenGzip(struct FreetypeIFace *Self, FT_Stream stream, FT_Stream source) {
	return FT_Stream_OpenGzip(stream,source);
}

FT_Error _impl_FT_Gzip_Uncompress(struct FreetypeIFace *Self, FT_Memory memory, FT_Byte* output, FT_ULong* output_len, const FT_Byte* input, FT_ULong input_len) {
	return FT_Gzip_Uncompress(memory,output,output_len,input,input_len);
}

FT_Error _impl_FT_Library_SetLcdFilter(struct FreetypeIFace *Self, FT_Library library, FT_LcdFilter filter) {
	return FT_Library_SetLcdFilter(library,filter);
}

FT_Error _impl_FT_Library_SetLcdFilterWeights(struct FreetypeIFace *Self, FT_Library library, unsigned char * weights) {
	return FT_Library_SetLcdFilterWeights(library,weights);
}

FT_Error _impl_FT_Library_SetLcdGeometry(struct FreetypeIFace *Self, FT_Library library, FT_Vector sub[3]) {
	return FT_Library_SetLcdGeometry(library, sub);
}

FT_ListNode _impl_FT_List_Find(struct FreetypeIFace *Self, FT_List list, void* data) {
	return FT_List_Find(list,data);
}

void _impl_FT_List_Add(struct FreetypeIFace *Self, FT_List list, FT_ListNode node) {
	FT_List_Add(list,node);
}

void _impl_FT_List_Insert(struct FreetypeIFace *Self, FT_List list, FT_ListNode node) {
	FT_List_Insert(list,node);
}

void _impl_FT_List_Remove(struct FreetypeIFace *Self, FT_List list, FT_ListNode node) {
	FT_List_Remove(list,node);
}

void _impl_FT_List_Up(struct FreetypeIFace *Self, FT_List list, FT_ListNode node) {
	FT_List_Up(list,node);
}

FT_Error _impl_FT_List_Iterate(struct FreetypeIFace *Self, FT_List list, FT_List_Iterator iterator, void* user) {
	return FT_List_Iterate(list,iterator,user);
}

void _impl_FT_List_Finalize(struct FreetypeIFace *Self, FT_List list, FT_List_Destructor destroy, FT_Memory memory, void* user) {
	FT_List_Finalize(list,destroy,memory,user);
}

void _impl_FT_Trace_Set_Level(struct FreetypeIFace *Self, const char* tracing_level) {
	FT_Trace_Set_Level(tracing_level);
}

void _impl_FT_Trace_Set_Default_Level(struct FreetypeIFace *Self) {
	FT_Trace_Set_Default_Level();
}

void _impl_FT_Set_Log_Handler(struct FreetypeIFace *Self, FT_Custom_Log_Handler handler) {
	FT_Set_Log_Handler(handler);
}

void _impl_FT_Set_Default_Log_Handler(struct FreetypeIFace *Self) {
	FT_Set_Default_Log_Handler();
}

FT_Error _impl_FT_Stream_OpenLZW(struct FreetypeIFace *Self, FT_Stream stream, FT_Stream source) {
	return FT_Stream_OpenLZW(stream,source);
}

FT_Error _impl_FT_Get_Multi_Master(struct FreetypeIFace *Self, FT_Face face, FT_Multi_Master * amaster) {
	return FT_Get_Multi_Master(face,amaster);
}

FT_Error _impl_FT_Get_MM_Var(struct FreetypeIFace *Self, FT_Face face, FT_MM_Var* * amaster) {
	return FT_Get_MM_Var(face,amaster);
}

FT_Error _impl_FT_Done_MM_Var(struct FreetypeIFace *Self, FT_Library library, FT_MM_Var * amaster) {
	return FT_Done_MM_Var(library,amaster);
}

FT_Error _impl_FT_Set_MM_Design_Coordinates(struct FreetypeIFace *Self, FT_Face face, FT_UInt num_coords, FT_Long* coords) {
	return FT_Set_MM_Design_Coordinates(face,num_coords,coords);
}

FT_Error _impl_FT_Set_Var_Design_Coordinates(struct FreetypeIFace *Self, FT_Face face, FT_UInt num_coords, FT_Fixed* coords) {
	return FT_Set_Var_Design_Coordinates(face,num_coords,coords);
}

FT_Error _impl_FT_Get_Var_Design_Coordinates(struct FreetypeIFace *Self, FT_Face face, FT_UInt num_coords, FT_Fixed* coords) {
	return FT_Get_Var_Design_Coordinates(face,num_coords,coords);
}

FT_Error _impl_FT_Set_MM_Blend_Coordinates(struct FreetypeIFace *Self, FT_Face face, FT_UInt num_coords, FT_Fixed* coords) {
	return FT_Set_MM_Blend_Coordinates(face,num_coords,coords);
}

FT_Error _impl_FT_Get_MM_Blend_Coordinates(struct FreetypeIFace *Self, FT_Face face, FT_UInt num_coords, FT_Fixed* coords) {
	return FT_Get_MM_Blend_Coordinates(face,num_coords,coords);
}

FT_Error _impl_FT_Set_Var_Blend_Coordinates(struct FreetypeIFace *Self, FT_Face face, FT_UInt num_coords, FT_Fixed* coords) {
	return FT_Set_Var_Blend_Coordinates(face,num_coords,coords);
}

FT_Error _impl_FT_Get_Var_Blend_Coordinates(struct FreetypeIFace *Self, FT_Face face, FT_UInt num_coords, FT_Fixed* coords) {
	return FT_Get_Var_Blend_Coordinates(face,num_coords,coords);
}

FT_Error _impl_FT_Set_MM_WeightVector(struct FreetypeIFace *Self, FT_Face face, FT_UInt len, FT_Fixed* weightvector) {
	return FT_Set_MM_WeightVector(face,len,weightvector);
}

FT_Error _impl_FT_Get_MM_WeightVector(struct FreetypeIFace *Self, FT_Face face, FT_UInt* len, FT_Fixed* weightvector) {
	return FT_Get_MM_WeightVector(face,len,weightvector);
}

FT_Error _impl_FT_Get_Var_Axis_Flags(struct FreetypeIFace *Self, FT_MM_Var* master, FT_UInt axis_index, FT_UInt* flags) {
	return FT_Get_Var_Axis_Flags(master,axis_index,flags);
}

FT_Error _impl_FT_Set_Named_Instance(struct FreetypeIFace *Self, FT_Face face, FT_UInt instance_index) {
	return FT_Set_Named_Instance(face,instance_index);
}

FT_Error _impl_FT_Get_Default_Named_Instance(struct FreetypeIFace *Self, FT_Face face, FT_UInt * instance_index) {
	return FT_Get_Default_Named_Instance(face,instance_index);
}

FT_Error _impl_FT_Add_Module(struct FreetypeIFace *Self, FT_Library library, const FT_Module_Class* clazz) {
	return FT_Add_Module(library,clazz);
}

FT_Module _impl_FT_Get_Module(struct FreetypeIFace *Self, FT_Library library, const char* module_name) {
	return FT_Get_Module(library,module_name);
}

FT_Error _impl_FT_Remove_Module(struct FreetypeIFace *Self, FT_Library library, FT_Module module) {
	return FT_Remove_Module(library,module);
}

FT_Error _impl_FT_Property_Set(struct FreetypeIFace *Self, FT_Library library, const FT_String* module_name, const FT_String* property_name, const void* value) {
	return FT_Property_Set(library,module_name,property_name,value);
}

FT_Error _impl_FT_Property_Get(struct FreetypeIFace *Self, FT_Library library, const FT_String* module_name, const FT_String* property_name, void* value) {
	return FT_Property_Get(library,module_name,property_name,value);
}

void _impl_FT_Set_Default_Properties(struct FreetypeIFace *Self, FT_Library library) {
	FT_Set_Default_Properties(library);
}

FT_Error _impl_FT_Reference_Library(struct FreetypeIFace *Self, FT_Library library) {
	return FT_Reference_Library(library);
}

FT_Error _impl_FT_New_Library(struct FreetypeIFace *Self, FT_Memory memory, FT_Library * alibrary) {
	return FT_New_Library(memory,alibrary);
}

FT_Error _impl_FT_Done_Library(struct FreetypeIFace *Self, FT_Library library) {
	return FT_Done_Library(library);
}

void _impl_FT_Set_Debug_Hook(struct FreetypeIFace *Self, FT_Library library, FT_UInt hook_index, FT_DebugHook_Func debug_hook) {
	FT_Set_Debug_Hook(library,hook_index,debug_hook);
}

void _impl_FT_Add_Default_Modules(struct FreetypeIFace *Self, FT_Library library) {
	FT_Add_Default_Modules(library);
}

FT_TrueTypeEngineType _impl_FT_Get_TrueType_Engine_Type(struct FreetypeIFace *Self, FT_Library library) {
	return FT_Get_TrueType_Engine_Type(library);
}

FT_Error _impl_FT_OpenType_Validate(struct FreetypeIFace *Self, FT_Face face, FT_UInt validation_flags, FT_Bytes * BASE_table, FT_Bytes * GDEF_table, FT_Bytes * GPOS_table, FT_Bytes * GSUB_table, FT_Bytes * JSTF_table) {
	return FT_OpenType_Validate(face,validation_flags,BASE_table,GDEF_table,GPOS_table,GSUB_table,JSTF_table);
}

void _impl_FT_OpenType_Free(struct FreetypeIFace *Self, FT_Face face, FT_Bytes table) {
	FT_OpenType_Free(face,table);
}

FT_Error _impl_FT_Outline_Decompose(struct FreetypeIFace *Self, FT_Outline* outline, const FT_Outline_Funcs* func_interface, void* user) {
	return FT_Outline_Decompose(outline,func_interface,user);
}

FT_Error _impl_FT_Outline_New(struct FreetypeIFace *Self, FT_Library library, FT_UInt numPoints, FT_Int numContours, FT_Outline * anoutline) {
	return FT_Outline_New(library,numPoints,numContours,anoutline);
}

FT_Error _impl_FT_Outline_Done(struct FreetypeIFace *Self, FT_Library library, FT_Outline* outline) {
	return FT_Outline_Done(library,outline);
}

FT_Error _impl_FT_Outline_Check(struct FreetypeIFace *Self, FT_Outline* outline) {
	return FT_Outline_Check(outline);
}

void _impl_FT_Outline_Get_CBox(struct FreetypeIFace *Self, const FT_Outline* outline, FT_BBox * acbox) {
	FT_Outline_Get_CBox(outline,acbox);
}

void _impl_FT_Outline_Translate(struct FreetypeIFace *Self, const FT_Outline* outline, FT_Pos xOffset, FT_Pos yOffset) {
	FT_Outline_Translate(outline,xOffset,yOffset);
}

FT_Error _impl_FT_Outline_Copy(struct FreetypeIFace *Self, const FT_Outline* source, FT_Outline * target) {
	return FT_Outline_Copy(source,target);
}

void _impl_FT_Outline_Transform(struct FreetypeIFace *Self, const FT_Outline* outline, const FT_Matrix* matrix) {
	FT_Outline_Transform(outline,matrix);
}

FT_Error _impl_FT_Outline_Embolden(struct FreetypeIFace *Self, FT_Outline* outline, FT_Pos strength) {
	return FT_Outline_Embolden(outline,strength);
}

FT_Error _impl_FT_Outline_EmboldenXY(struct FreetypeIFace *Self, FT_Outline* outline, FT_Pos xstrength, FT_Pos ystrength) {
	return FT_Outline_EmboldenXY(outline,xstrength,ystrength);
}

void _impl_FT_Outline_Reverse(struct FreetypeIFace *Self, FT_Outline* outline) {
	FT_Outline_Reverse(outline);
}

FT_Error _impl_FT_Outline_Get_Bitmap(struct FreetypeIFace *Self, FT_Library library, FT_Outline* outline, const FT_Bitmap * abitmap) {
	return FT_Outline_Get_Bitmap(library,outline,abitmap);
}

FT_Error _impl_FT_Outline_Render(struct FreetypeIFace *Self, FT_Library library, FT_Outline* outline, FT_Raster_Params* params) {
	return FT_Outline_Render(library,outline,params);
}

FT_Orientation _impl_FT_Outline_Get_Orientation(struct FreetypeIFace *Self, FT_Outline* outline) {
	return FT_Outline_Get_Orientation(outline);
}

FT_Error _impl_FT_Get_PFR_Metrics(struct FreetypeIFace *Self, FT_Face face, FT_UInt * aoutline_resolution, FT_UInt * ametrics_resolution, FT_Fixed * ametrics_x_scale, FT_Fixed * ametrics_y_scale) {
	return FT_Get_PFR_Metrics(face,aoutline_resolution,ametrics_resolution,ametrics_x_scale,ametrics_y_scale);
}

FT_Error _impl_FT_Get_PFR_Kerning(struct FreetypeIFace *Self, FT_Face face, FT_UInt left, FT_UInt right, FT_Vector * avector) {
	return FT_Get_PFR_Kerning(face,left,right,avector);
}

FT_Error _impl_FT_Get_PFR_Advance(struct FreetypeIFace *Self, FT_Face face, FT_UInt gindex, FT_Pos * aadvance) {
	return FT_Get_PFR_Advance(face,gindex,aadvance);
}

FT_Renderer _impl_FT_Get_Renderer(struct FreetypeIFace *Self, FT_Library library, FT_Glyph_Format format) {
	return FT_Get_Renderer(library,format);
}

FT_Error _impl_FT_Set_Renderer(struct FreetypeIFace *Self, FT_Library library, FT_Renderer renderer, FT_UInt num_params, FT_Parameter* parameters) {
	return FT_Set_Renderer(library,renderer,num_params,parameters);
}

FT_Error _impl_FT_New_Size(struct FreetypeIFace *Self, FT_Face face, FT_Size* size) {
	return FT_New_Size(face,size);
}

FT_Error _impl_FT_Done_Size(struct FreetypeIFace *Self, FT_Size size) {
	return FT_Done_Size(size);
}

FT_Error _impl_FT_Activate_Size(struct FreetypeIFace *Self, FT_Size size) {
	return FT_Activate_Size(size);
}

FT_UInt _impl_FT_Get_Sfnt_Name_Count(struct FreetypeIFace *Self, FT_Face face) {
	return FT_Get_Sfnt_Name_Count(face);
}

FT_Error _impl_FT_Get_Sfnt_Name(struct FreetypeIFace *Self, FT_Face face, FT_UInt idx, FT_SfntName * aname) {
	return FT_Get_Sfnt_Name(face,idx,aname);
}

FT_Error _impl_FT_Get_Sfnt_LangTag(struct FreetypeIFace *Self, FT_Face face, FT_UInt langID, FT_SfntLangTag * alangTag) {
	return FT_Get_Sfnt_LangTag(face,langID,alangTag);
}

FT_StrokerBorder _impl_FT_Outline_GetInsideBorder(struct FreetypeIFace *Self, FT_Outline* outline) {
	return FT_Outline_GetInsideBorder(outline);
}

FT_StrokerBorder _impl_FT_Outline_GetOutsideBorder(struct FreetypeIFace *Self, FT_Outline* outline) {
	return FT_Outline_GetOutsideBorder(outline);
}

FT_Error _impl_FT_Stroker_New(struct FreetypeIFace *Self, FT_Library library, FT_Stroker * astroker) {
	return FT_Stroker_New(library,astroker);
}

void _impl_FT_Stroker_Set(struct FreetypeIFace *Self, FT_Stroker stroker, FT_Fixed radius, FT_Stroker_LineCap line_cap, FT_Stroker_LineJoin line_join, FT_Fixed miter_limit) {
	FT_Stroker_Set(stroker,radius,line_cap,line_join,miter_limit);
}

void _impl_FT_Stroker_Rewind(struct FreetypeIFace *Self, FT_Stroker stroker) {
	FT_Stroker_Rewind(stroker);
}

FT_Error _impl_FT_Stroker_ParseOutline(struct FreetypeIFace *Self, FT_Stroker stroker, FT_Outline* outline, FT_Bool opened) {
	return FT_Stroker_ParseOutline(stroker,outline,opened);
}

FT_Error _impl_FT_Stroker_BeginSubPath(struct FreetypeIFace *Self, FT_Stroker stroker, FT_Vector* to, FT_Bool open) {
	return FT_Stroker_BeginSubPath(stroker,to,open);
}

FT_Error _impl_FT_Stroker_EndSubPath(struct FreetypeIFace *Self, FT_Stroker stroker) {
	return FT_Stroker_EndSubPath(stroker);
}

FT_Error _impl_FT_Stroker_LineTo(struct FreetypeIFace *Self, FT_Stroker stroker, FT_Vector* to) {
	return FT_Stroker_LineTo(stroker,to);
}

FT_Error _impl_FT_Stroker_ConicTo(struct FreetypeIFace *Self, FT_Stroker stroker, FT_Vector* control, FT_Vector* to) {
	return FT_Stroker_ConicTo(stroker,control,to);
}

FT_Error _impl_FT_Stroker_CubicTo(struct FreetypeIFace *Self, FT_Stroker stroker, FT_Vector* control1, FT_Vector* control2, FT_Vector* to) {
	return FT_Stroker_CubicTo(stroker,control1,control2,to);
}

FT_Error _impl_FT_Stroker_GetBorderCounts(struct FreetypeIFace *Self, FT_Stroker stroker, FT_StrokerBorder border, FT_UInt * anum_points, FT_UInt * anum_contours) {
	return FT_Stroker_GetBorderCounts(stroker,border,anum_points,anum_contours);
}

void _impl_FT_Stroker_ExportBorder(struct FreetypeIFace *Self, FT_Stroker stroker, FT_StrokerBorder border, FT_Outline* outline) {
	FT_Stroker_ExportBorder(stroker,border,outline);
}

FT_Error _impl_FT_Stroker_GetCounts(struct FreetypeIFace *Self, FT_Stroker stroker, FT_UInt * anum_points, FT_UInt * anum_contours) {
	return FT_Stroker_GetCounts(stroker,anum_points,anum_contours);
}

void _impl_FT_Stroker_Export(struct FreetypeIFace *Self, FT_Stroker stroker, FT_Outline* outline) {
	FT_Stroker_Export(stroker,outline);
}

void _impl_FT_Stroker_Done(struct FreetypeIFace *Self, FT_Stroker stroker) {
	FT_Stroker_Done(stroker);
}

FT_Error _impl_FT_Glyph_Stroke(struct FreetypeIFace *Self, FT_Glyph * pglyph, FT_Stroker stroker, FT_Bool destroy) {
	return FT_Glyph_Stroke(pglyph,stroker,destroy);
}

FT_Error _impl_FT_Glyph_StrokeBorder(struct FreetypeIFace *Self, FT_Glyph * pglyph, FT_Stroker stroker, FT_Bool inside, FT_Bool destroy) {
	return FT_Glyph_StrokeBorder(pglyph,stroker,inside,destroy);
}

void _impl_FT_GlyphSlot_Embolden(struct FreetypeIFace *Self, FT_GlyphSlot slot) {
	FT_GlyphSlot_Embolden(slot);
}

void _impl_FT_GlyphSlot_AdjustWeight(struct FreetypeIFace *Self, FT_GlyphSlot slot, FT_Fixed xdelta, FT_Fixed ydelta) {
	FT_GlyphSlot_AdjustWeight(slot,xdelta,ydelta);
}

void _impl_FT_GlyphSlot_Oblique(struct FreetypeIFace *Self, FT_GlyphSlot slot) {
	FT_GlyphSlot_Oblique(slot);
}

void _impl_FT_GlyphSlot_Slant(struct FreetypeIFace *Self, FT_GlyphSlot slot, FT_Fixed xslant, FT_Fixed yslant) {
	FT_GlyphSlot_Slant(slot,xslant,yslant);
}

FT_Fixed _impl_FT_Sin(struct FreetypeIFace *Self, FT_Angle angle) {
	return FT_Sin(angle);
}

FT_Fixed _impl_FT_Cos(struct FreetypeIFace *Self, FT_Angle angle) {
	return FT_Cos(angle);
}

FT_Fixed _impl_FT_Tan(struct FreetypeIFace *Self, FT_Angle angle) {
	return FT_Tan(angle);
}

FT_Angle _impl_FT_Atan2(struct FreetypeIFace *Self, FT_Fixed x, FT_Fixed y) {
	return FT_Atan2(x,y);
}

FT_Angle _impl_FT_Angle_Diff(struct FreetypeIFace *Self, FT_Angle angle1, FT_Angle angle2) {
	return FT_Angle_Diff(angle1,angle2);
}

void _impl_FT_Vector_Unit(struct FreetypeIFace *Self, FT_Vector* vec, FT_Angle angle) {
	FT_Vector_Unit(vec,angle);
}

void _impl_FT_Vector_Rotate(struct FreetypeIFace *Self, FT_Vector* vec, FT_Angle angle) {
	FT_Vector_Rotate(vec,angle);
}

FT_Fixed _impl_FT_Vector_Length(struct FreetypeIFace *Self, FT_Vector* vec) {
	return FT_Vector_Length(vec);
}

void _impl_FT_Vector_Polarize(struct FreetypeIFace *Self, FT_Vector* vec, FT_Fixed * length, FT_Angle * angle) {
	FT_Vector_Polarize(vec,length,angle);
}

void _impl_FT_Vector_From_Polar(struct FreetypeIFace *Self, FT_Vector* vec, FT_Fixed length, FT_Angle angle) {
	FT_Vector_From_Polar(vec,length,angle);
}

FT_Error _impl_FT_Get_WinFNT_Header(struct FreetypeIFace *Self, FT_Face face, FT_WinFNT_HeaderRec * aheader) {
	return FT_Get_WinFNT_Header(face,aheader);
}

FT_Int _impl_FT_Has_PS_Glyph_Names(struct FreetypeIFace *Self, FT_Face face) {
	return FT_Has_PS_Glyph_Names(face);
}

FT_Error _impl_FT_Get_PS_Font_Info(struct FreetypeIFace *Self, FT_Face face, PS_FontInfo afont_info) {
	return FT_Get_PS_Font_Info(face,afont_info);
}

FT_Error _impl_FT_Get_PS_Font_Private(struct FreetypeIFace *Self, FT_Face face, PS_Private afont_private) {
	return FT_Get_PS_Font_Private(face,afont_private);
}

FT_Long _impl_FT_Get_PS_Font_Value(struct FreetypeIFace *Self, FT_Face face, PS_Dict_Keys key, FT_UInt idx, void * value, FT_Long value_len) {
	return FT_Get_PS_Font_Value(face,key,idx,value,value_len);
}

void* _impl_FT_Get_Sfnt_Table(struct FreetypeIFace *Self, FT_Face face, FT_Sfnt_Tag tag) {
	return FT_Get_Sfnt_Table(face,tag);
}

FT_Error _impl_FT_Load_Sfnt_Table(struct FreetypeIFace *Self, FT_Face face, FT_ULong tag, FT_Long offset, FT_Byte* buffer, FT_ULong* length) {
	return FT_Load_Sfnt_Table(face,tag,offset,buffer,length);
}

FT_Error _impl_FT_Sfnt_Table_Info(struct FreetypeIFace *Self, FT_Face face, FT_UInt table_index, FT_ULong * tag, FT_ULong * length) {
	return FT_Sfnt_Table_Info(face,table_index,tag,length);
}

FT_ULong _impl_FT_Get_CMap_Language_ID(struct FreetypeIFace *Self, FT_CharMap charmap) {
	return FT_Get_CMap_Language_ID(charmap);
}

FT_Long _impl_FT_Get_CMap_Format(struct FreetypeIFace *Self, FT_CharMap charmap) {
	return FT_Get_CMap_Format(charmap);
}
