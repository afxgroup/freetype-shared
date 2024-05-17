#include <stdarg.h>
#include <exec/exec.h>
#include <proto/exec.h>
#include <proto/freetype.h>

#include <freetype/freetype.h>
#include <freetype/freetype.h>
#include <freetype/ftbdf.h>
#include <freetype/ftcache.h>
#include <freetype/ftcolor.h>
#include <freetype/ftgxval.h>
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

FT_Error FT_Init_FreeType(FT_Library * alibrary) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Init_FreeType(alibrary);
}

FT_Error FT_Done_FreeType(FT_Library library) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Done_FreeType(library);
}

FT_Error FT_New_Face(FT_Library library, const char* filepathname, FT_Long face_index, FT_Face * aface) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_New_Face(library,filepathname,face_index,aface);
}

FT_Error FT_New_Memory_Face(FT_Library library, const FT_Byte* file_base, FT_Long file_size, FT_Long face_index, FT_Face * aface) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_New_Memory_Face(library,file_base,file_size,face_index,aface);
}

FT_Error FT_Open_Face(FT_Library library, const FT_Open_Args* args, FT_Long face_index, FT_Face * aface) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Open_Face(library,args,face_index,aface);
}

FT_Error FT_Attach_File(FT_Face face, const char* filepathname) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Attach_File(face,filepathname);
}

FT_Error FT_Attach_Stream(FT_Face face, const FT_Open_Args* parameters) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Attach_Stream(face,parameters);
}

FT_Error FT_Reference_Face(FT_Face face) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Reference_Face(face);
}

FT_Error FT_Done_Face(FT_Face face) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Done_Face(face);
}

FT_Error FT_Select_Size(FT_Face face, FT_Int strike_index) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Select_Size(face,strike_index);
}

FT_Error FT_Request_Size(FT_Face face, FT_Size_Request req) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Request_Size(face,req);
}

FT_Error FT_Set_Char_Size(FT_Face face, FT_F26Dot6 char_width, FT_F26Dot6 char_height, FT_UInt horz_resolution, FT_UInt vert_resolution) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Set_Char_Size(face,char_width,char_height,horz_resolution,vert_resolution);
}

FT_Error FT_Set_Pixel_Sizes(FT_Face face, FT_UInt pixel_width, FT_UInt pixel_height) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Set_Pixel_Sizes(face,pixel_width,pixel_height);
}

FT_Error FT_Load_Glyph(FT_Face face, FT_UInt glyph_index, FT_Int32 load_flags) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Load_Glyph(face,glyph_index,load_flags);
}

FT_Error FT_Load_Char(FT_Face face, FT_ULong char_code, FT_Int32 load_flags) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Load_Char(face,char_code,load_flags);
}

void FT_Set_Transform(FT_Face face, FT_Matrix* matrix, FT_Vector* delta) {
	extern struct FreetypeIFace *IFreetype;

	IFreetype->FT_Set_Transform(face,matrix,delta);
}

void FT_Get_Transform(FT_Face face, FT_Matrix* matrix, FT_Vector* delta) {
	extern struct FreetypeIFace *IFreetype;

	IFreetype->FT_Get_Transform(face,matrix,delta);
}

FT_Error FT_Render_Glyph(FT_GlyphSlot slot, FT_Render_Mode render_mode) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Render_Glyph(slot,render_mode);
}

FT_Error FT_Get_Kerning(FT_Face face, FT_UInt left_glyph, FT_UInt right_glyph, FT_UInt kern_mode, FT_Vector * akerning) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_Kerning(face,left_glyph,right_glyph,kern_mode,akerning);
}

FT_Error FT_Get_Track_Kerning(FT_Face face, FT_Fixed point_size, FT_Int degree, FT_Fixed* akerning) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_Track_Kerning(face,point_size,degree,akerning);
}

FT_Error FT_Select_Charmap(FT_Face face, FT_Encoding encoding) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Select_Charmap(face,encoding);
}

FT_Error FT_Set_Charmap(FT_Face face, FT_CharMap charmap) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Set_Charmap(face,charmap);
}

FT_Int FT_Get_Charmap_Index(FT_CharMap charmap) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_Charmap_Index(charmap);
}

FT_UInt FT_Get_Char_Index(FT_Face face, FT_ULong charcode) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_Char_Index(face,charcode);
}

FT_ULong FT_Get_First_Char(FT_Face face, FT_UInt * agindex) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_First_Char(face,agindex);
}

FT_ULong FT_Get_Next_Char(FT_Face face, FT_ULong char_code, FT_UInt * agindex) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_Next_Char(face,char_code,agindex);
}

FT_Error FT_Face_Properties(FT_Face face, FT_UInt num_properties, FT_Parameter* properties) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Face_Properties(face,num_properties,properties);
}

FT_UInt FT_Get_Name_Index(FT_Face face, const FT_String* glyph_name) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_Name_Index(face,glyph_name);
}

FT_Error FT_Get_Glyph_Name(FT_Face face, FT_UInt glyph_index, FT_Pointer buffer, FT_UInt buffer_max) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_Glyph_Name(face,glyph_index,buffer,buffer_max);
}

const char* FT_Get_Postscript_Name(FT_Face face) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_Postscript_Name(face);
}

FT_Error FT_Get_SubGlyph_Info(FT_GlyphSlot glyph, FT_UInt sub_index, FT_Int * p_index, FT_UInt * p_flags, FT_Int * p_arg1, FT_Int * p_arg2, FT_Matrix * p_transform) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_SubGlyph_Info(glyph,sub_index,p_index,p_flags,p_arg1,p_arg2,p_transform);
}

FT_UShort FT_Get_FSType_Flags(FT_Face face) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_FSType_Flags(face);
}

FT_UInt FT_Face_GetCharVariantIndex(FT_Face face, FT_ULong charcode, FT_ULong variantSelector) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Face_GetCharVariantIndex(face,charcode,variantSelector);
}

FT_Int FT_Face_GetCharVariantIsDefault(FT_Face face, FT_ULong charcode, FT_ULong variantSelector) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Face_GetCharVariantIsDefault(face,charcode,variantSelector);
}

FT_UInt32* FT_Face_GetVariantSelectors(FT_Face face) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Face_GetVariantSelectors(face);
}

FT_UInt32* FT_Face_GetVariantsOfChar(FT_Face face, FT_ULong charcode) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Face_GetVariantsOfChar(face,charcode);
}

FT_UInt32* FT_Face_GetCharsOfVariant(FT_Face face, FT_ULong variantSelector) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Face_GetCharsOfVariant(face,variantSelector);
}

FT_Long FT_MulDiv(FT_Long a, FT_Long b, FT_Long c) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_MulDiv(a,b,c);
}

FT_Long FT_MulFix(FT_Long a, FT_Long b) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_MulFix(a,b);
}

FT_Long FT_DivFix(FT_Long a, FT_Long b) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_DivFix(a,b);
}

FT_Fixed FT_RoundFix(FT_Fixed a) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_RoundFix(a);
}

FT_Fixed FT_CeilFix(FT_Fixed a) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_CeilFix(a);
}

FT_Fixed FT_FloorFix(FT_Fixed a) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_FloorFix(a);
}

void FT_Vector_Transform(FT_Vector* vector, const FT_Matrix* matrix) {
	extern struct FreetypeIFace *IFreetype;

	IFreetype->FT_Vector_Transform(vector,matrix);
}

void FT_Library_Version(FT_Library library, FT_Int * amajor, FT_Int * aminor, FT_Int * apatch) {
	extern struct FreetypeIFace *IFreetype;

	IFreetype->FT_Library_Version(library,amajor,aminor,apatch);
}

FT_Bool FT_Face_CheckTrueTypePatents(FT_Face face) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Face_CheckTrueTypePatents(face);
}

FT_Bool FT_Face_SetUnpatentedHinting(FT_Face face, FT_Bool value) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Face_SetUnpatentedHinting(face,value);
}

FT_Error FT_Get_Advance(FT_Face face, FT_UInt gindex, FT_Int32 load_flags, FT_Fixed * padvance) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_Advance(face,gindex,load_flags,padvance);
}

FT_Error FT_Get_Advances(FT_Face face, FT_UInt start, FT_UInt count, FT_Int32 load_flags, FT_Fixed * padvances) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_Advances(face,start,count,load_flags,padvances);
}

FT_Error FT_Outline_Get_BBox(FT_Outline* outline, FT_BBox * abbox) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Outline_Get_BBox(outline,abbox);
}

FT_Error FT_Get_BDF_Charset_ID(FT_Face face, const char* * acharset_encoding, const char* * acharset_registry) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_BDF_Charset_ID(face,acharset_encoding,acharset_registry);
}

FT_Error FT_Get_BDF_Property(FT_Face face, const char* prop_name, BDF_PropertyRec * aproperty) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_BDF_Property(face,prop_name,aproperty);
}

void FT_Bitmap_Init(FT_Bitmap * abitmap) {
	extern struct FreetypeIFace *IFreetype;

	IFreetype->FT_Bitmap_Init(abitmap);
}

void FT_Bitmap_New(FT_Bitmap * abitmap) {
	extern struct FreetypeIFace *IFreetype;

	IFreetype->FT_Bitmap_New(abitmap);
}

FT_Error FT_Bitmap_Copy(FT_Library library, const FT_Bitmap * source, FT_Bitmap * target) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Bitmap_Copy(library,source,target);
}

FT_Error FT_Bitmap_Embolden(FT_Library library, FT_Bitmap* bitmap, FT_Pos xStrength, FT_Pos yStrength) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Bitmap_Embolden(library,bitmap,xStrength,yStrength);
}

FT_Error FT_Bitmap_Convert(FT_Library library, const FT_Bitmap * source, FT_Bitmap * target, FT_Int alignment) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Bitmap_Convert(library,source,target,alignment);
}

FT_Error FT_Bitmap_Blend(FT_Library library, const FT_Bitmap* source, const FT_Vector source_offset, FT_Bitmap* target, FT_Vector * atarget_offset, FT_Color color) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Bitmap_Blend(library,source,source_offset,target,atarget_offset,color);
}

FT_Error FT_GlyphSlot_Own_Bitmap(FT_GlyphSlot slot) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_GlyphSlot_Own_Bitmap(slot);
}

FT_Error FT_Bitmap_Done(FT_Library library, FT_Bitmap * bitmap) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Bitmap_Done(library,bitmap);
}

FT_Error FT_Stream_OpenBzip2(FT_Stream stream, FT_Stream source) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Stream_OpenBzip2(stream,source);
}

FT_Error FTC_Manager_New(FT_Library library, FT_UInt max_faces, FT_UInt max_sizes, FT_ULong max_bytes, FTC_Face_Requester requester, FT_Pointer req_data, FTC_Manager * amanager) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FTC_Manager_New(library,max_faces,max_sizes,max_bytes,requester,req_data,amanager);
}

void FTC_Manager_Reset(FTC_Manager manager) {
	extern struct FreetypeIFace *IFreetype;

	IFreetype->FTC_Manager_Reset(manager);
}

void FTC_Manager_Done(FTC_Manager manager) {
	extern struct FreetypeIFace *IFreetype;

	IFreetype->FTC_Manager_Done(manager);
}

FT_Error FTC_Manager_LookupFace(FTC_Manager manager, FTC_FaceID face_id, FT_Face * aface) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FTC_Manager_LookupFace(manager,face_id,aface);
}

FT_Error FTC_Manager_LookupSize(FTC_Manager manager, FTC_Scaler scaler, FT_Size * asize) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FTC_Manager_LookupSize(manager,scaler,asize);
}

void FTC_Node_Unref(FTC_Node node, FTC_Manager manager) {
	extern struct FreetypeIFace *IFreetype;

	IFreetype->FTC_Node_Unref(node,manager);
}

void FTC_Manager_RemoveFaceID(FTC_Manager manager, FTC_FaceID face_id) {
	extern struct FreetypeIFace *IFreetype;

	IFreetype->FTC_Manager_RemoveFaceID(manager,face_id);
}

FT_Error FTC_CMapCache_New(FTC_Manager manager, FTC_CMapCache * acache) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FTC_CMapCache_New(manager,acache);
}

FT_UInt FTC_CMapCache_Lookup(FTC_CMapCache cache, FTC_FaceID face_id, FT_Int cmap_index, FT_UInt32 char_code) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FTC_CMapCache_Lookup(cache,face_id,cmap_index,char_code);
}

FT_Error FTC_ImageCache_New(FTC_Manager manager, FTC_ImageCache * acache) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FTC_ImageCache_New(manager,acache);
}

FT_Error FTC_ImageCache_Lookup(FTC_ImageCache cache, FTC_ImageType type, FT_UInt gindex, FT_Glyph * aglyph, FTC_Node * anode) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FTC_ImageCache_Lookup(cache,type,gindex,aglyph,anode);
}

FT_Error FTC_ImageCache_LookupScaler(FTC_ImageCache cache, FTC_Scaler scaler, FT_ULong load_flags, FT_UInt gindex, FT_Glyph * aglyph, FTC_Node * anode) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FTC_ImageCache_LookupScaler(cache,scaler,load_flags,gindex,aglyph,anode);
}

FT_Error FTC_SBitCache_New(FTC_Manager manager, FTC_SBitCache * acache) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FTC_SBitCache_New(manager,acache);
}

FT_Error FTC_SBitCache_Lookup(FTC_SBitCache cache, FTC_ImageType type, FT_UInt gindex, FTC_SBit * sbit, FTC_Node * anode) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FTC_SBitCache_Lookup(cache,type,gindex,sbit,anode);
}

FT_Error FTC_SBitCache_LookupScaler(FTC_SBitCache cache, FTC_Scaler scaler, FT_ULong load_flags, FT_UInt gindex, FTC_SBit * sbit, FTC_Node * anode) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FTC_SBitCache_LookupScaler(cache,scaler,load_flags,gindex,sbit,anode);
}

FT_Error FT_Get_CID_Registry_Ordering_Supplement(FT_Face face, const char* * registry, const char* * ordering, FT_Int * supplement) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_CID_Registry_Ordering_Supplement(face,registry,ordering,supplement);
}

FT_Error FT_Get_CID_Is_Internally_CID_Keyed(FT_Face face, FT_Bool * is_cid) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_CID_Is_Internally_CID_Keyed(face,is_cid);
}

FT_Error FT_Get_CID_From_Glyph_Index(FT_Face face, FT_UInt glyph_index, FT_UInt * cid) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_CID_From_Glyph_Index(face,glyph_index,cid);
}

FT_Error FT_Palette_Data_Get(FT_Face face, FT_Palette_Data * apalette) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Palette_Data_Get(face,apalette);
}

FT_Error FT_Palette_Select(FT_Face face, FT_UShort palette_index, FT_Color* * apalette) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Palette_Select(face,palette_index,apalette);
}

FT_Error FT_Palette_Set_Foreground_Color(FT_Face face, FT_Color foreground_color) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Palette_Set_Foreground_Color(face,foreground_color);
}

FT_Bool FT_Get_Color_Glyph_Layer(FT_Face face, FT_UInt base_glyph, FT_UInt * aglyph_index, FT_UInt * acolor_index, FT_LayerIterator* iterator) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_Color_Glyph_Layer(face,base_glyph,aglyph_index,acolor_index,iterator);
}

FT_Bool FT_Get_Color_Glyph_Paint(FT_Face face, FT_UInt base_glyph, FT_Color_Root_Transform root_transform, FT_OpaquePaint* paint) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_Color_Glyph_Paint(face,base_glyph,root_transform,paint);
}

FT_Bool FT_Get_Color_Glyph_ClipBox(FT_Face face, FT_UInt base_glyph, FT_ClipBox* clip_box) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_Color_Glyph_ClipBox(face,base_glyph,clip_box);
}

FT_Bool FT_Get_Paint_Layers(FT_Face face, FT_LayerIterator* iterator, FT_OpaquePaint* paint) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_Paint_Layers(face,iterator,paint);
}

FT_Bool FT_Get_Colorline_Stops(FT_Face face, FT_ColorStop* color_stop, FT_ColorStopIterator* iterator) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_Colorline_Stops(face,color_stop,iterator);
}

FT_Bool FT_Get_Paint(FT_Face face, FT_OpaquePaint opaque_paint, FT_COLR_Paint* paint) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_Paint(face,opaque_paint,paint);
}

const char* FT_Error_String(FT_Error error_code) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Error_String(error_code);
}

const char* FT_Get_Font_Format(FT_Face face) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_Font_Format(face);
}

const char* FT_Get_X11_Font_Format(FT_Face face) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_X11_Font_Format(face);
}

FT_Int FT_Get_Gasp(FT_Face face, FT_UInt ppem) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_Gasp(face,ppem);
}

FT_Error FT_New_Glyph(FT_Library library, FT_Glyph_Format format, FT_Glyph * aglyph) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_New_Glyph(library,format,aglyph);
}

FT_Error FT_Get_Glyph(FT_GlyphSlot slot, FT_Glyph * aglyph) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_Glyph(slot,aglyph);
}

FT_Error FT_Glyph_Copy(FT_Glyph source, FT_Glyph * target) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Glyph_Copy(source,target);
}

FT_Error FT_Glyph_Transform(FT_Glyph glyph, const FT_Matrix* matrix, const FT_Vector* delta) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Glyph_Transform(glyph,matrix,delta);
}

void FT_Glyph_Get_CBox(FT_Glyph glyph, FT_UInt bbox_mode, FT_BBox * acbox) {
	extern struct FreetypeIFace *IFreetype;

	IFreetype->FT_Glyph_Get_CBox(glyph,bbox_mode,acbox);
}

FT_Error FT_Glyph_To_Bitmap(FT_Glyph* the_glyph, FT_Render_Mode render_mode, const FT_Vector* origin, FT_Bool destroy) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Glyph_To_Bitmap(the_glyph,render_mode,origin,destroy);
}

void FT_Done_Glyph(FT_Glyph glyph) {
	extern struct FreetypeIFace *IFreetype;

	IFreetype->FT_Done_Glyph(glyph);
}

void FT_Matrix_Multiply(const FT_Matrix* a, FT_Matrix* b) {
	extern struct FreetypeIFace *IFreetype;

	IFreetype->FT_Matrix_Multiply(a,b);
}

FT_Error FT_Matrix_Invert(FT_Matrix* matrix) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Matrix_Invert(matrix);
}

FT_Error FT_TrueTypeGX_Validate(FT_Face face, FT_UInt validation_flags, FT_Bytes tables[FT_VALIDATE_GX_LENGTH], FT_UInt table_length) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_TrueTypeGX_Validate(face,validation_flags,tables[FT_VALIDATE_GX_LENGTH],table_length);
}

void FT_TrueTypeGX_Free(FT_Face face, FT_Bytes table) {
	extern struct FreetypeIFace *IFreetype;

	IFreetype->FT_TrueTypeGX_Free(face,table);
}

FT_Error FT_ClassicKern_Validate(FT_Face face, FT_UInt validation_flags, FT_Bytes * ckern_table) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_ClassicKern_Validate(face,validation_flags,ckern_table);
}

void FT_ClassicKern_Free(FT_Face face, FT_Bytes table) {
	extern struct FreetypeIFace *IFreetype;

	IFreetype->FT_ClassicKern_Free(face,table);
}

FT_Error FT_Stream_OpenGzip(FT_Stream stream, FT_Stream source) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Stream_OpenGzip(stream,source);
}

FT_Error FT_Gzip_Uncompress(FT_Memory memory, FT_Byte* output, FT_ULong* output_len, const FT_Byte* input, FT_ULong input_len) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Gzip_Uncompress(memory,output,output_len,input,input_len);
}

FT_Error FT_Library_SetLcdFilter(FT_Library library, FT_LcdFilter filter) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Library_SetLcdFilter(library,filter);
}

FT_Error FT_Library_SetLcdFilterWeights(FT_Library library, unsigned char * weights) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Library_SetLcdFilterWeights(library,weights);
}

FT_Error FT_Library_SetLcdGeometry(FT_Library library, FT_Vector sub[3]) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Library_SetLcdGeometry(library,sub);
}

FT_ListNode FT_List_Find(FT_List list, void* data) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_List_Find(list,data);
}

void FT_List_Add(FT_List list, FT_ListNode node) {
	extern struct FreetypeIFace *IFreetype;

	IFreetype->FT_List_Add(list,node);
}

void FT_List_Insert(FT_List list, FT_ListNode node) {
	extern struct FreetypeIFace *IFreetype;

	IFreetype->FT_List_Insert(list,node);
}

void FT_List_Remove(FT_List list, FT_ListNode node) {
	extern struct FreetypeIFace *IFreetype;

	IFreetype->FT_List_Remove(list,node);
}

void FT_List_Up(FT_List list, FT_ListNode node) {
	extern struct FreetypeIFace *IFreetype;

	IFreetype->FT_List_Up(list,node);
}

FT_Error FT_List_Iterate(FT_List list, FT_List_Iterator iterator, void* user) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_List_Iterate(list,iterator,user);
}

void FT_List_Finalize(FT_List list, FT_List_Destructor destroy, FT_Memory memory, void* user) {
	extern struct FreetypeIFace *IFreetype;

	IFreetype->FT_List_Finalize(list,destroy,memory,user);
}

void FT_Trace_Set_Level(const char* tracing_level) {
	extern struct FreetypeIFace *IFreetype;

	IFreetype->FT_Trace_Set_Level(tracing_level);
}

void FT_Trace_Set_Default_Level() {
	extern struct FreetypeIFace *IFreetype;

	IFreetype->FT_Trace_Set_Default_Level();
}

void FT_Set_Log_Handler(FT_Custom_Log_Handler handler) {
	extern struct FreetypeIFace *IFreetype;

	IFreetype->FT_Set_Log_Handler(handler);
}

void FT_Set_Default_Log_Handler() {
	extern struct FreetypeIFace *IFreetype;

	IFreetype->FT_Set_Default_Log_Handler();
}

FT_Error FT_Stream_OpenLZW(FT_Stream stream, FT_Stream source) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Stream_OpenLZW(stream,source);
}

FT_Error FT_Get_Multi_Master(FT_Face face, FT_Multi_Master * amaster) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_Multi_Master(face,amaster);
}

FT_Error FT_Get_MM_Var(FT_Face face, FT_MM_Var* * amaster) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_MM_Var(face,amaster);
}

FT_Error FT_Done_MM_Var(FT_Library library, FT_MM_Var * amaster) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Done_MM_Var(library,amaster);
}

FT_Error FT_Set_MM_Design_Coordinates(FT_Face face, FT_UInt num_coords, FT_Long* coords) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Set_MM_Design_Coordinates(face,num_coords,coords);
}

FT_Error FT_Set_Var_Design_Coordinates(FT_Face face, FT_UInt num_coords, FT_Fixed* coords) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Set_Var_Design_Coordinates(face,num_coords,coords);
}

FT_Error FT_Get_Var_Design_Coordinates(FT_Face face, FT_UInt num_coords, FT_Fixed* coords) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_Var_Design_Coordinates(face,num_coords,coords);
}

FT_Error FT_Set_MM_Blend_Coordinates(FT_Face face, FT_UInt num_coords, FT_Fixed* coords) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Set_MM_Blend_Coordinates(face,num_coords,coords);
}

FT_Error FT_Get_MM_Blend_Coordinates(FT_Face face, FT_UInt num_coords, FT_Fixed* coords) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_MM_Blend_Coordinates(face,num_coords,coords);
}

FT_Error FT_Set_Var_Blend_Coordinates(FT_Face face, FT_UInt num_coords, FT_Fixed* coords) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Set_Var_Blend_Coordinates(face,num_coords,coords);
}

FT_Error FT_Get_Var_Blend_Coordinates(FT_Face face, FT_UInt num_coords, FT_Fixed* coords) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_Var_Blend_Coordinates(face,num_coords,coords);
}

FT_Error FT_Set_MM_WeightVector(FT_Face face, FT_UInt len, FT_Fixed* weightvector) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Set_MM_WeightVector(face,len,weightvector);
}

FT_Error FT_Get_MM_WeightVector(FT_Face face, FT_UInt* len, FT_Fixed* weightvector) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_MM_WeightVector(face,len,weightvector);
}

FT_Error FT_Get_Var_Axis_Flags(FT_MM_Var* master, FT_UInt axis_index, FT_UInt* flags) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_Var_Axis_Flags(master,axis_index,flags);
}

FT_Error FT_Set_Named_Instance(FT_Face face, FT_UInt instance_index) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Set_Named_Instance(face,instance_index);
}

FT_Error FT_Get_Default_Named_Instance(FT_Face face, FT_UInt * instance_index) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_Default_Named_Instance(face,instance_index);
}

FT_Error FT_Add_Module(FT_Library library, const FT_Module_Class* clazz) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Add_Module(library,clazz);
}

FT_Module FT_Get_Module(FT_Library library, const char* module_name) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_Module(library,module_name);
}

FT_Error FT_Remove_Module(FT_Library library, FT_Module module) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Remove_Module(library,module);
}

FT_Error FT_Property_Set(FT_Library library, const FT_String* module_name, const FT_String* property_name, const void* value) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Property_Set(library,module_name,property_name,value);
}

FT_Error FT_Property_Get(FT_Library library, const FT_String* module_name, const FT_String* property_name, void* value) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Property_Get(library,module_name,property_name,value);
}

void FT_Set_Default_Properties(FT_Library library) {
	extern struct FreetypeIFace *IFreetype;

	IFreetype->FT_Set_Default_Properties(library);
}

FT_Error FT_Reference_Library(FT_Library library) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Reference_Library(library);
}

FT_Error FT_New_Library(FT_Memory memory, FT_Library * alibrary) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_New_Library(memory,alibrary);
}

FT_Error FT_Done_Library(FT_Library library) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Done_Library(library);
}

void FT_Set_Debug_Hook(FT_Library library, FT_UInt hook_index, FT_DebugHook_Func debug_hook) {
	extern struct FreetypeIFace *IFreetype;

	IFreetype->FT_Set_Debug_Hook(library,hook_index,debug_hook);
}

void FT_Add_Default_Modules(FT_Library library) {
	extern struct FreetypeIFace *IFreetype;

	IFreetype->FT_Add_Default_Modules(library);
}

FT_TrueTypeEngineType FT_Get_TrueType_Engine_Type(FT_Library library) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_TrueType_Engine_Type(library);
}

FT_Error FT_OpenType_Validate(FT_Face face, FT_UInt validation_flags, FT_Bytes * BASE_table, FT_Bytes * GDEF_table, FT_Bytes * GPOS_table, FT_Bytes * GSUB_table, FT_Bytes * JSTF_table) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_OpenType_Validate(face,validation_flags,BASE_table,GDEF_table,GPOS_table,GSUB_table,JSTF_table);
}

void FT_OpenType_Free(FT_Face face, FT_Bytes table) {
	extern struct FreetypeIFace *IFreetype;

	IFreetype->FT_OpenType_Free(face,table);
}

FT_Error FT_Outline_Decompose(FT_Outline* outline, const FT_Outline_Funcs* func_interface, void* user) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Outline_Decompose(outline,func_interface,user);
}

FT_Error FT_Outline_New(FT_Library library, FT_UInt numPoints, FT_Int numContours, FT_Outline * anoutline) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Outline_New(library,numPoints,numContours,anoutline);
}

FT_Error FT_Outline_Done(FT_Library library, FT_Outline* outline) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Outline_Done(library,outline);
}

FT_Error FT_Outline_Check(FT_Outline* outline) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Outline_Check(outline);
}

void FT_Outline_Get_CBox(const FT_Outline* outline, FT_BBox * acbox) {
	extern struct FreetypeIFace *IFreetype;

	IFreetype->FT_Outline_Get_CBox(outline,acbox);
}

void FT_Outline_Translate(const FT_Outline* outline, FT_Pos xOffset, FT_Pos yOffset) {
	extern struct FreetypeIFace *IFreetype;

	IFreetype->FT_Outline_Translate(outline,xOffset,yOffset);
}

FT_Error FT_Outline_Copy(const FT_Outline* source, FT_Outline * target) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Outline_Copy(source,target);
}

void FT_Outline_Transform(const FT_Outline* outline, const FT_Matrix* matrix) {
	extern struct FreetypeIFace *IFreetype;

	IFreetype->FT_Outline_Transform(outline,matrix);
}

FT_Error FT_Outline_Embolden(FT_Outline* outline, FT_Pos strength) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Outline_Embolden(outline,strength);
}

FT_Error FT_Outline_EmboldenXY(FT_Outline* outline, FT_Pos xstrength, FT_Pos ystrength) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Outline_EmboldenXY(outline,xstrength,ystrength);
}

void FT_Outline_Reverse(FT_Outline* outline) {
	extern struct FreetypeIFace *IFreetype;

	IFreetype->FT_Outline_Reverse(outline);
}

FT_Error FT_Outline_Get_Bitmap(FT_Library library, FT_Outline* outline, const FT_Bitmap * abitmap) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Outline_Get_Bitmap(library,outline,abitmap);
}

FT_Error FT_Outline_Render(FT_Library library, FT_Outline* outline, FT_Raster_Params* params) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Outline_Render(library,outline,params);
}

FT_Orientation FT_Outline_Get_Orientation(FT_Outline* outline) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Outline_Get_Orientation(outline);
}

FT_Error FT_Get_PFR_Metrics(FT_Face face, FT_UInt * aoutline_resolution, FT_UInt * ametrics_resolution, FT_Fixed * ametrics_x_scale, FT_Fixed * ametrics_y_scale) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_PFR_Metrics(face,aoutline_resolution,ametrics_resolution,ametrics_x_scale,ametrics_y_scale);
}

FT_Error FT_Get_PFR_Kerning(FT_Face face, FT_UInt left, FT_UInt right, FT_Vector * avector) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_PFR_Kerning(face,left,right,avector);
}

FT_Error FT_Get_PFR_Advance(FT_Face face, FT_UInt gindex, FT_Pos * aadvance) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_PFR_Advance(face,gindex,aadvance);
}

FT_Renderer FT_Get_Renderer(FT_Library library, FT_Glyph_Format format) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_Renderer(library,format);
}

FT_Error FT_Set_Renderer(FT_Library library, FT_Renderer renderer, FT_UInt num_params, FT_Parameter* parameters) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Set_Renderer(library,renderer,num_params,parameters);
}

FT_Error FT_New_Size(FT_Face face, FT_Size* size) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_New_Size(face,size);
}

FT_Error FT_Done_Size(FT_Size size) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Done_Size(size);
}

FT_Error FT_Activate_Size(FT_Size size) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Activate_Size(size);
}

FT_UInt FT_Get_Sfnt_Name_Count(FT_Face face) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_Sfnt_Name_Count(face);
}

FT_Error FT_Get_Sfnt_Name(FT_Face face, FT_UInt idx, FT_SfntName * aname) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_Sfnt_Name(face,idx,aname);
}

FT_Error FT_Get_Sfnt_LangTag(FT_Face face, FT_UInt langID, FT_SfntLangTag * alangTag) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_Sfnt_LangTag(face,langID,alangTag);
}

FT_StrokerBorder FT_Outline_GetInsideBorder(FT_Outline* outline) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Outline_GetInsideBorder(outline);
}

FT_StrokerBorder FT_Outline_GetOutsideBorder(FT_Outline* outline) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Outline_GetOutsideBorder(outline);
}

FT_Error FT_Stroker_New(FT_Library library, FT_Stroker * astroker) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Stroker_New(library,astroker);
}

void FT_Stroker_Set(FT_Stroker stroker, FT_Fixed radius, FT_Stroker_LineCap line_cap, FT_Stroker_LineJoin line_join, FT_Fixed miter_limit) {
	extern struct FreetypeIFace *IFreetype;

	IFreetype->FT_Stroker_Set(stroker,radius,line_cap,line_join,miter_limit);
}

void FT_Stroker_Rewind(FT_Stroker stroker) {
	extern struct FreetypeIFace *IFreetype;

	IFreetype->FT_Stroker_Rewind(stroker);
}

FT_Error FT_Stroker_ParseOutline(FT_Stroker stroker, FT_Outline* outline, FT_Bool opened) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Stroker_ParseOutline(stroker,outline,opened);
}

FT_Error FT_Stroker_BeginSubPath(FT_Stroker stroker, FT_Vector* to, FT_Bool open) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Stroker_BeginSubPath(stroker,to,open);
}

FT_Error FT_Stroker_EndSubPath(FT_Stroker stroker) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Stroker_EndSubPath(stroker);
}

FT_Error FT_Stroker_LineTo(FT_Stroker stroker, FT_Vector* to) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Stroker_LineTo(stroker,to);
}

FT_Error FT_Stroker_ConicTo(FT_Stroker stroker, FT_Vector* control, FT_Vector* to) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Stroker_ConicTo(stroker,control,to);
}

FT_Error FT_Stroker_CubicTo(FT_Stroker stroker, FT_Vector* control1, FT_Vector* control2, FT_Vector* to) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Stroker_CubicTo(stroker,control1,control2,to);
}

FT_Error FT_Stroker_GetBorderCounts(FT_Stroker stroker, FT_StrokerBorder border, FT_UInt * anum_points, FT_UInt * anum_contours) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Stroker_GetBorderCounts(stroker,border,anum_points,anum_contours);
}

void FT_Stroker_ExportBorder(FT_Stroker stroker, FT_StrokerBorder border, FT_Outline* outline) {
	extern struct FreetypeIFace *IFreetype;

	IFreetype->FT_Stroker_ExportBorder(stroker,border,outline);
}

FT_Error FT_Stroker_GetCounts(FT_Stroker stroker, FT_UInt * anum_points, FT_UInt * anum_contours) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Stroker_GetCounts(stroker,anum_points,anum_contours);
}

void FT_Stroker_Export(FT_Stroker stroker, FT_Outline* outline) {
	extern struct FreetypeIFace *IFreetype;

	IFreetype->FT_Stroker_Export(stroker,outline);
}

void FT_Stroker_Done(FT_Stroker stroker) {
	extern struct FreetypeIFace *IFreetype;

	IFreetype->FT_Stroker_Done(stroker);
}

FT_Error FT_Glyph_Stroke(FT_Glyph * pglyph, FT_Stroker stroker, FT_Bool destroy) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Glyph_Stroke(pglyph,stroker,destroy);
}

FT_Error FT_Glyph_StrokeBorder(FT_Glyph * pglyph, FT_Stroker stroker, FT_Bool inside, FT_Bool destroy) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Glyph_StrokeBorder(pglyph,stroker,inside,destroy);
}

void FT_GlyphSlot_Embolden(FT_GlyphSlot slot) {
	extern struct FreetypeIFace *IFreetype;

	IFreetype->FT_GlyphSlot_Embolden(slot);
}

void FT_GlyphSlot_AdjustWeight(FT_GlyphSlot slot, FT_Fixed xdelta, FT_Fixed ydelta) {
	extern struct FreetypeIFace *IFreetype;

	IFreetype->FT_GlyphSlot_AdjustWeight(slot,xdelta,ydelta);
}

void FT_GlyphSlot_Oblique(FT_GlyphSlot slot) {
	extern struct FreetypeIFace *IFreetype;

	IFreetype->FT_GlyphSlot_Oblique(slot);
}

void FT_GlyphSlot_Slant(FT_GlyphSlot slot, FT_Fixed xslant, FT_Fixed yslant) {
	extern struct FreetypeIFace *IFreetype;

	IFreetype->FT_GlyphSlot_Slant(slot,xslant,yslant);
}

FT_Fixed FT_Sin(FT_Angle angle) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Sin(angle);
}

FT_Fixed FT_Cos(FT_Angle angle) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Cos(angle);
}

FT_Fixed FT_Tan(FT_Angle angle) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Tan(angle);
}

FT_Angle FT_Atan2(FT_Fixed x, FT_Fixed y) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Atan2(x,y);
}

FT_Angle FT_Angle_Diff(FT_Angle angle1, FT_Angle angle2) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Angle_Diff(angle1,angle2);
}

void FT_Vector_Unit(FT_Vector* vec, FT_Angle angle) {
	extern struct FreetypeIFace *IFreetype;

	IFreetype->FT_Vector_Unit(vec,angle);
}

void FT_Vector_Rotate(FT_Vector* vec, FT_Angle angle) {
	extern struct FreetypeIFace *IFreetype;

	IFreetype->FT_Vector_Rotate(vec,angle);
}

FT_Fixed FT_Vector_Length(FT_Vector* vec) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Vector_Length(vec);
}

void FT_Vector_Polarize(FT_Vector* vec, FT_Fixed * length, FT_Angle * angle) {
	extern struct FreetypeIFace *IFreetype;

	IFreetype->FT_Vector_Polarize(vec,length,angle);
}

void FT_Vector_From_Polar(FT_Vector* vec, FT_Fixed length, FT_Angle angle) {
	extern struct FreetypeIFace *IFreetype;

	IFreetype->FT_Vector_From_Polar(vec,length,angle);
}

FT_Error FT_Get_WinFNT_Header(FT_Face face, FT_WinFNT_HeaderRec * aheader) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_WinFNT_Header(face,aheader);
}

FT_Int FT_Has_PS_Glyph_Names(FT_Face face) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Has_PS_Glyph_Names(face);
}

FT_Error FT_Get_PS_Font_Info(FT_Face face, PS_FontInfo afont_info) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_PS_Font_Info(face,afont_info);
}

FT_Error FT_Get_PS_Font_Private(FT_Face face, PS_Private afont_private) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_PS_Font_Private(face,afont_private);
}

FT_Long FT_Get_PS_Font_Value(FT_Face face, PS_Dict_Keys key, FT_UInt idx, void * value, FT_Long value_len) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_PS_Font_Value(face,key,idx,value,value_len);
}

void* FT_Get_Sfnt_Table(FT_Face face, FT_Sfnt_Tag tag) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_Sfnt_Table(face,tag);
}

FT_Error FT_Load_Sfnt_Table(FT_Face face, FT_ULong tag, FT_Long offset, FT_Byte* buffer, FT_ULong* length) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Load_Sfnt_Table(face,tag,offset,buffer,length);
}

FT_Error FT_Sfnt_Table_Info(FT_Face face, FT_UInt table_index, FT_ULong * tag, FT_ULong * length) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Sfnt_Table_Info(face,table_index,tag,length);
}

FT_ULong FT_Get_CMap_Language_ID(FT_CharMap charmap) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_CMap_Language_ID(charmap);
}

FT_Long FT_Get_CMap_Format(FT_CharMap charmap) {
	extern struct FreetypeIFace *IFreetype;

	return IFreetype->FT_Get_CMap_Format(charmap);
}

