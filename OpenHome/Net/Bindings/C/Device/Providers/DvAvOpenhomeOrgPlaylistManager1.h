/**
 * Provider for the av.openhome.org:PlaylistManager:1 UPnP service
 */
#ifndef HEADER_DVAVOPENHOMEORGPLAYLISTMANAGER1_C
#define HEADER_DVAVOPENHOMEORGPLAYLISTMANAGER1_C

#include <OpenHome/OhNetDefines.h>
#include <OpenHome/OsTypes.h>
#include <OpenHome/Net/C/DvDevice.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup DvProviderAvOpenhomeOrgPlaylistManager1
 * @ingroup Providers
 * @{
 */

/**
 * Callback which runs when the Metadata action is invoked
 *
 * @param[in]  aPtr      Opaque data passed to DvProviderAvOpenhomeOrgPlaylistManager1EnableActionMetadata
 * @param[in]  aVersion  Version of the service being used.  Will be <= the version advertised by the provider
 * @param[out] aMetadata
 *
 * @return  0 if the action succeeded; non-zero if the action failed
 */
typedef int32_t (STDCALL *CallbackPlaylistManager1Metadata)(void* aPtr, uint32_t aVersion, char** aMetadata);
/**
 * Callback which runs when the ImagesXml action is invoked
 *
 * @param[in]  aPtr      Opaque data passed to DvProviderAvOpenhomeOrgPlaylistManager1EnableActionImagesXml
 * @param[in]  aVersion  Version of the service being used.  Will be <= the version advertised by the provider
 * @param[out] aImagesXml
 *
 * @return  0 if the action succeeded; non-zero if the action failed
 */
typedef int32_t (STDCALL *CallbackPlaylistManager1ImagesXml)(void* aPtr, uint32_t aVersion, char** aImagesXml);
/**
 * Callback which runs when the PlaylistReadArray action is invoked
 *
 * @param[in]  aPtr      Opaque data passed to DvProviderAvOpenhomeOrgPlaylistManager1EnableActionPlaylistReadArray
 * @param[in]  aVersion  Version of the service being used.  Will be <= the version advertised by the provider
 * @param[in]  aId
 * @param[out] aArray
 * @param[out] aArrayLen
 *
 * @return  0 if the action succeeded; non-zero if the action failed
 */
typedef int32_t (STDCALL *CallbackPlaylistManager1PlaylistReadArray)(void* aPtr, uint32_t aVersion, uint32_t aId, char** aArray, uint32_t* aArrayLen);
/**
 * Callback which runs when the PlaylistReadMetadata action is invoked
 *
 * @param[in]  aPtr      Opaque data passed to DvProviderAvOpenhomeOrgPlaylistManager1EnableActionPlaylistReadMetadata
 * @param[in]  aVersion  Version of the service being used.  Will be <= the version advertised by the provider
 * @param[in]  aIdList
 * @param[out] aMetadata
 *
 * @return  0 if the action succeeded; non-zero if the action failed
 */
typedef int32_t (STDCALL *CallbackPlaylistManager1PlaylistReadMetadata)(void* aPtr, uint32_t aVersion, const char* aIdList, char** aMetadata);
/**
 * Callback which runs when the PlaylistRead action is invoked
 *
 * @param[in]  aPtr      Opaque data passed to DvProviderAvOpenhomeOrgPlaylistManager1EnableActionPlaylistRead
 * @param[in]  aVersion  Version of the service being used.  Will be <= the version advertised by the provider
 * @param[in]  aId
 * @param[out] aName
 * @param[out] aDescription
 * @param[out] aImageId
 *
 * @return  0 if the action succeeded; non-zero if the action failed
 */
typedef int32_t (STDCALL *CallbackPlaylistManager1PlaylistRead)(void* aPtr, uint32_t aVersion, uint32_t aId, char** aName, char** aDescription, uint32_t* aImageId);
/**
 * Callback which runs when the PlaylistUpdate action is invoked
 *
 * @param[in]  aPtr      Opaque data passed to DvProviderAvOpenhomeOrgPlaylistManager1EnableActionPlaylistUpdate
 * @param[in]  aVersion  Version of the service being used.  Will be <= the version advertised by the provider
 * @param[in]  aId
 * @param[in]  aName
 * @param[in]  aDescription
 * @param[in]  aImageId
 *
 * @return  0 if the action succeeded; non-zero if the action failed
 */
typedef int32_t (STDCALL *CallbackPlaylistManager1PlaylistUpdate)(void* aPtr, uint32_t aVersion, uint32_t aId, const char* aName, const char* aDescription, uint32_t aImageId);
/**
 * Callback which runs when the PlaylistInsert action is invoked
 *
 * @param[in]  aPtr      Opaque data passed to DvProviderAvOpenhomeOrgPlaylistManager1EnableActionPlaylistInsert
 * @param[in]  aVersion  Version of the service being used.  Will be <= the version advertised by the provider
 * @param[in]  aAfterId
 * @param[in]  aName
 * @param[in]  aDescription
 * @param[in]  aImageId
 * @param[out] aNewId
 *
 * @return  0 if the action succeeded; non-zero if the action failed
 */
typedef int32_t (STDCALL *CallbackPlaylistManager1PlaylistInsert)(void* aPtr, uint32_t aVersion, uint32_t aAfterId, const char* aName, const char* aDescription, uint32_t aImageId, uint32_t* aNewId);
/**
 * Callback which runs when the PlaylistDeleteId action is invoked
 *
 * @param[in]  aPtr      Opaque data passed to DvProviderAvOpenhomeOrgPlaylistManager1EnableActionPlaylistDeleteId
 * @param[in]  aVersion  Version of the service being used.  Will be <= the version advertised by the provider
 * @param[in]  aValue
 *
 * @return  0 if the action succeeded; non-zero if the action failed
 */
typedef int32_t (STDCALL *CallbackPlaylistManager1PlaylistDeleteId)(void* aPtr, uint32_t aVersion, uint32_t aValue);
/**
 * Callback which runs when the PlaylistsMax action is invoked
 *
 * @param[in]  aPtr      Opaque data passed to DvProviderAvOpenhomeOrgPlaylistManager1EnableActionPlaylistsMax
 * @param[in]  aVersion  Version of the service being used.  Will be <= the version advertised by the provider
 * @param[out] aValue
 *
 * @return  0 if the action succeeded; non-zero if the action failed
 */
typedef int32_t (STDCALL *CallbackPlaylistManager1PlaylistsMax)(void* aPtr, uint32_t aVersion, uint32_t* aValue);
/**
 * Callback which runs when the TracksMax action is invoked
 *
 * @param[in]  aPtr      Opaque data passed to DvProviderAvOpenhomeOrgPlaylistManager1EnableActionTracksMax
 * @param[in]  aVersion  Version of the service being used.  Will be <= the version advertised by the provider
 * @param[out] aValue
 *
 * @return  0 if the action succeeded; non-zero if the action failed
 */
typedef int32_t (STDCALL *CallbackPlaylistManager1TracksMax)(void* aPtr, uint32_t aVersion, uint32_t* aValue);
/**
 * Callback which runs when the PlaylistArrays action is invoked
 *
 * @param[in]  aPtr      Opaque data passed to DvProviderAvOpenhomeOrgPlaylistManager1EnableActionPlaylistArrays
 * @param[in]  aVersion  Version of the service being used.  Will be <= the version advertised by the provider
 * @param[out] aToken
 * @param[out] aIdArray
 * @param[out] aIdArrayLen
 * @param[out] aTokenArray
 * @param[out] aTokenArrayLen
 *
 * @return  0 if the action succeeded; non-zero if the action failed
 */
typedef int32_t (STDCALL *CallbackPlaylistManager1PlaylistArrays)(void* aPtr, uint32_t aVersion, uint32_t* aToken, char** aIdArray, uint32_t* aIdArrayLen, char** aTokenArray, uint32_t* aTokenArrayLen);
/**
 * Callback which runs when the PlaylistArraysChanged action is invoked
 *
 * @param[in]  aPtr      Opaque data passed to DvProviderAvOpenhomeOrgPlaylistManager1EnableActionPlaylistArraysChanged
 * @param[in]  aVersion  Version of the service being used.  Will be <= the version advertised by the provider
 * @param[in]  aToken
 * @param[out] aValue
 *
 * @return  0 if the action succeeded; non-zero if the action failed
 */
typedef int32_t (STDCALL *CallbackPlaylistManager1PlaylistArraysChanged)(void* aPtr, uint32_t aVersion, uint32_t aToken, uint32_t* aValue);
/**
 * Callback which runs when the Read action is invoked
 *
 * @param[in]  aPtr      Opaque data passed to DvProviderAvOpenhomeOrgPlaylistManager1EnableActionRead
 * @param[in]  aVersion  Version of the service being used.  Will be <= the version advertised by the provider
 * @param[in]  aId
 * @param[in]  aTrackId
 * @param[out] aMetadata
 *
 * @return  0 if the action succeeded; non-zero if the action failed
 */
typedef int32_t (STDCALL *CallbackPlaylistManager1Read)(void* aPtr, uint32_t aVersion, uint32_t aId, uint32_t aTrackId, char** aMetadata);
/**
 * Callback which runs when the ReadList action is invoked
 *
 * @param[in]  aPtr      Opaque data passed to DvProviderAvOpenhomeOrgPlaylistManager1EnableActionReadList
 * @param[in]  aVersion  Version of the service being used.  Will be <= the version advertised by the provider
 * @param[in]  aId
 * @param[in]  aTrackIdList
 * @param[out] aTrackList
 *
 * @return  0 if the action succeeded; non-zero if the action failed
 */
typedef int32_t (STDCALL *CallbackPlaylistManager1ReadList)(void* aPtr, uint32_t aVersion, uint32_t aId, const char* aTrackIdList, char** aTrackList);
/**
 * Callback which runs when the Insert action is invoked
 *
 * @param[in]  aPtr      Opaque data passed to DvProviderAvOpenhomeOrgPlaylistManager1EnableActionInsert
 * @param[in]  aVersion  Version of the service being used.  Will be <= the version advertised by the provider
 * @param[in]  aId
 * @param[in]  aAfterTrackId
 * @param[in]  aUdn
 * @param[in]  aMetadataId
 * @param[out] aNewTrackId
 *
 * @return  0 if the action succeeded; non-zero if the action failed
 */
typedef int32_t (STDCALL *CallbackPlaylistManager1Insert)(void* aPtr, uint32_t aVersion, uint32_t aId, uint32_t aAfterTrackId, const char* aUdn, const char* aMetadataId, uint32_t* aNewTrackId);
/**
 * Callback which runs when the DeleteId action is invoked
 *
 * @param[in]  aPtr      Opaque data passed to DvProviderAvOpenhomeOrgPlaylistManager1EnableActionDeleteId
 * @param[in]  aVersion  Version of the service being used.  Will be <= the version advertised by the provider
 * @param[in]  aTrackId
 * @param[in]  aValue
 *
 * @return  0 if the action succeeded; non-zero if the action failed
 */
typedef int32_t (STDCALL *CallbackPlaylistManager1DeleteId)(void* aPtr, uint32_t aVersion, uint32_t aTrackId, uint32_t aValue);
/**
 * Callback which runs when the DeleteAll action is invoked
 *
 * @param[in]  aPtr      Opaque data passed to DvProviderAvOpenhomeOrgPlaylistManager1EnableActionDeleteAll
 * @param[in]  aVersion  Version of the service being used.  Will be <= the version advertised by the provider
 * @param[in]  aTrackId
 *
 * @return  0 if the action succeeded; non-zero if the action failed
 */
typedef int32_t (STDCALL *CallbackPlaylistManager1DeleteAll)(void* aPtr, uint32_t aVersion, uint32_t aTrackId);

/**
 * Provider constructor
 *
 * @param[in] aDevice  Handle returned by DvDeviceCreate[NoResources]
 *
 * @return  Handle to this provider
 */
DllExport THandle STDCALL DvProviderAvOpenhomeOrgPlaylistManager1Create(DvDeviceC aDevice);

/**
 * Provider destructor
 *
 * @param[in] aProvider  Handle returned by DvProviderAvOpenhomeOrgPlaylistManager1Create
 */
DllExport void STDCALL DvProviderAvOpenhomeOrgPlaylistManager1Destroy(THandle aProvider);

/**
 * Register a callback for the action Metadata
 *
 * If this is called, the action's availability will be published in the device's service.xml.
 * If this is not called, any attempt to invoke the action on a control point will fail.
 *
 * @param[in] aProvider  Handle returned by DvProviderAvOpenhomeOrgPlaylistManager1Create
 * @param[in] aCallback  Callback which will be run when the action is invoked
 * @param[in] aPtr       Client-specified data which will be passed to the callback
 */
DllExport void STDCALL DvProviderAvOpenhomeOrgPlaylistManager1EnableActionMetadata(THandle aProvider, CallbackPlaylistManager1Metadata aCallback, void* aPtr);
/**
 * Register a callback for the action ImagesXml
 *
 * If this is called, the action's availability will be published in the device's service.xml.
 * If this is not called, any attempt to invoke the action on a control point will fail.
 *
 * @param[in] aProvider  Handle returned by DvProviderAvOpenhomeOrgPlaylistManager1Create
 * @param[in] aCallback  Callback which will be run when the action is invoked
 * @param[in] aPtr       Client-specified data which will be passed to the callback
 */
DllExport void STDCALL DvProviderAvOpenhomeOrgPlaylistManager1EnableActionImagesXml(THandle aProvider, CallbackPlaylistManager1ImagesXml aCallback, void* aPtr);
/**
 * Register a callback for the action PlaylistReadArray
 *
 * If this is called, the action's availability will be published in the device's service.xml.
 * If this is not called, any attempt to invoke the action on a control point will fail.
 *
 * @param[in] aProvider  Handle returned by DvProviderAvOpenhomeOrgPlaylistManager1Create
 * @param[in] aCallback  Callback which will be run when the action is invoked
 * @param[in] aPtr       Client-specified data which will be passed to the callback
 */
DllExport void STDCALL DvProviderAvOpenhomeOrgPlaylistManager1EnableActionPlaylistReadArray(THandle aProvider, CallbackPlaylistManager1PlaylistReadArray aCallback, void* aPtr);
/**
 * Register a callback for the action PlaylistReadMetadata
 *
 * If this is called, the action's availability will be published in the device's service.xml.
 * If this is not called, any attempt to invoke the action on a control point will fail.
 *
 * @param[in] aProvider  Handle returned by DvProviderAvOpenhomeOrgPlaylistManager1Create
 * @param[in] aCallback  Callback which will be run when the action is invoked
 * @param[in] aPtr       Client-specified data which will be passed to the callback
 */
DllExport void STDCALL DvProviderAvOpenhomeOrgPlaylistManager1EnableActionPlaylistReadMetadata(THandle aProvider, CallbackPlaylistManager1PlaylistReadMetadata aCallback, void* aPtr);
/**
 * Register a callback for the action PlaylistRead
 *
 * If this is called, the action's availability will be published in the device's service.xml.
 * If this is not called, any attempt to invoke the action on a control point will fail.
 *
 * @param[in] aProvider  Handle returned by DvProviderAvOpenhomeOrgPlaylistManager1Create
 * @param[in] aCallback  Callback which will be run when the action is invoked
 * @param[in] aPtr       Client-specified data which will be passed to the callback
 */
DllExport void STDCALL DvProviderAvOpenhomeOrgPlaylistManager1EnableActionPlaylistRead(THandle aProvider, CallbackPlaylistManager1PlaylistRead aCallback, void* aPtr);
/**
 * Register a callback for the action PlaylistUpdate
 *
 * If this is called, the action's availability will be published in the device's service.xml.
 * If this is not called, any attempt to invoke the action on a control point will fail.
 *
 * @param[in] aProvider  Handle returned by DvProviderAvOpenhomeOrgPlaylistManager1Create
 * @param[in] aCallback  Callback which will be run when the action is invoked
 * @param[in] aPtr       Client-specified data which will be passed to the callback
 */
DllExport void STDCALL DvProviderAvOpenhomeOrgPlaylistManager1EnableActionPlaylistUpdate(THandle aProvider, CallbackPlaylistManager1PlaylistUpdate aCallback, void* aPtr);
/**
 * Register a callback for the action PlaylistInsert
 *
 * If this is called, the action's availability will be published in the device's service.xml.
 * If this is not called, any attempt to invoke the action on a control point will fail.
 *
 * @param[in] aProvider  Handle returned by DvProviderAvOpenhomeOrgPlaylistManager1Create
 * @param[in] aCallback  Callback which will be run when the action is invoked
 * @param[in] aPtr       Client-specified data which will be passed to the callback
 */
DllExport void STDCALL DvProviderAvOpenhomeOrgPlaylistManager1EnableActionPlaylistInsert(THandle aProvider, CallbackPlaylistManager1PlaylistInsert aCallback, void* aPtr);
/**
 * Register a callback for the action PlaylistDeleteId
 *
 * If this is called, the action's availability will be published in the device's service.xml.
 * If this is not called, any attempt to invoke the action on a control point will fail.
 *
 * @param[in] aProvider  Handle returned by DvProviderAvOpenhomeOrgPlaylistManager1Create
 * @param[in] aCallback  Callback which will be run when the action is invoked
 * @param[in] aPtr       Client-specified data which will be passed to the callback
 */
DllExport void STDCALL DvProviderAvOpenhomeOrgPlaylistManager1EnableActionPlaylistDeleteId(THandle aProvider, CallbackPlaylistManager1PlaylistDeleteId aCallback, void* aPtr);
/**
 * Register a callback for the action PlaylistsMax
 *
 * If this is called, the action's availability will be published in the device's service.xml.
 * If this is not called, any attempt to invoke the action on a control point will fail.
 *
 * @param[in] aProvider  Handle returned by DvProviderAvOpenhomeOrgPlaylistManager1Create
 * @param[in] aCallback  Callback which will be run when the action is invoked
 * @param[in] aPtr       Client-specified data which will be passed to the callback
 */
DllExport void STDCALL DvProviderAvOpenhomeOrgPlaylistManager1EnableActionPlaylistsMax(THandle aProvider, CallbackPlaylistManager1PlaylistsMax aCallback, void* aPtr);
/**
 * Register a callback for the action TracksMax
 *
 * If this is called, the action's availability will be published in the device's service.xml.
 * If this is not called, any attempt to invoke the action on a control point will fail.
 *
 * @param[in] aProvider  Handle returned by DvProviderAvOpenhomeOrgPlaylistManager1Create
 * @param[in] aCallback  Callback which will be run when the action is invoked
 * @param[in] aPtr       Client-specified data which will be passed to the callback
 */
DllExport void STDCALL DvProviderAvOpenhomeOrgPlaylistManager1EnableActionTracksMax(THandle aProvider, CallbackPlaylistManager1TracksMax aCallback, void* aPtr);
/**
 * Register a callback for the action PlaylistArrays
 *
 * If this is called, the action's availability will be published in the device's service.xml.
 * If this is not called, any attempt to invoke the action on a control point will fail.
 *
 * @param[in] aProvider  Handle returned by DvProviderAvOpenhomeOrgPlaylistManager1Create
 * @param[in] aCallback  Callback which will be run when the action is invoked
 * @param[in] aPtr       Client-specified data which will be passed to the callback
 */
DllExport void STDCALL DvProviderAvOpenhomeOrgPlaylistManager1EnableActionPlaylistArrays(THandle aProvider, CallbackPlaylistManager1PlaylistArrays aCallback, void* aPtr);
/**
 * Register a callback for the action PlaylistArraysChanged
 *
 * If this is called, the action's availability will be published in the device's service.xml.
 * If this is not called, any attempt to invoke the action on a control point will fail.
 *
 * @param[in] aProvider  Handle returned by DvProviderAvOpenhomeOrgPlaylistManager1Create
 * @param[in] aCallback  Callback which will be run when the action is invoked
 * @param[in] aPtr       Client-specified data which will be passed to the callback
 */
DllExport void STDCALL DvProviderAvOpenhomeOrgPlaylistManager1EnableActionPlaylistArraysChanged(THandle aProvider, CallbackPlaylistManager1PlaylistArraysChanged aCallback, void* aPtr);
/**
 * Register a callback for the action Read
 *
 * If this is called, the action's availability will be published in the device's service.xml.
 * If this is not called, any attempt to invoke the action on a control point will fail.
 *
 * @param[in] aProvider  Handle returned by DvProviderAvOpenhomeOrgPlaylistManager1Create
 * @param[in] aCallback  Callback which will be run when the action is invoked
 * @param[in] aPtr       Client-specified data which will be passed to the callback
 */
DllExport void STDCALL DvProviderAvOpenhomeOrgPlaylistManager1EnableActionRead(THandle aProvider, CallbackPlaylistManager1Read aCallback, void* aPtr);
/**
 * Register a callback for the action ReadList
 *
 * If this is called, the action's availability will be published in the device's service.xml.
 * If this is not called, any attempt to invoke the action on a control point will fail.
 *
 * @param[in] aProvider  Handle returned by DvProviderAvOpenhomeOrgPlaylistManager1Create
 * @param[in] aCallback  Callback which will be run when the action is invoked
 * @param[in] aPtr       Client-specified data which will be passed to the callback
 */
DllExport void STDCALL DvProviderAvOpenhomeOrgPlaylistManager1EnableActionReadList(THandle aProvider, CallbackPlaylistManager1ReadList aCallback, void* aPtr);
/**
 * Register a callback for the action Insert
 *
 * If this is called, the action's availability will be published in the device's service.xml.
 * If this is not called, any attempt to invoke the action on a control point will fail.
 *
 * @param[in] aProvider  Handle returned by DvProviderAvOpenhomeOrgPlaylistManager1Create
 * @param[in] aCallback  Callback which will be run when the action is invoked
 * @param[in] aPtr       Client-specified data which will be passed to the callback
 */
DllExport void STDCALL DvProviderAvOpenhomeOrgPlaylistManager1EnableActionInsert(THandle aProvider, CallbackPlaylistManager1Insert aCallback, void* aPtr);
/**
 * Register a callback for the action DeleteId
 *
 * If this is called, the action's availability will be published in the device's service.xml.
 * If this is not called, any attempt to invoke the action on a control point will fail.
 *
 * @param[in] aProvider  Handle returned by DvProviderAvOpenhomeOrgPlaylistManager1Create
 * @param[in] aCallback  Callback which will be run when the action is invoked
 * @param[in] aPtr       Client-specified data which will be passed to the callback
 */
DllExport void STDCALL DvProviderAvOpenhomeOrgPlaylistManager1EnableActionDeleteId(THandle aProvider, CallbackPlaylistManager1DeleteId aCallback, void* aPtr);
/**
 * Register a callback for the action DeleteAll
 *
 * If this is called, the action's availability will be published in the device's service.xml.
 * If this is not called, any attempt to invoke the action on a control point will fail.
 *
 * @param[in] aProvider  Handle returned by DvProviderAvOpenhomeOrgPlaylistManager1Create
 * @param[in] aCallback  Callback which will be run when the action is invoked
 * @param[in] aPtr       Client-specified data which will be passed to the callback
 */
DllExport void STDCALL DvProviderAvOpenhomeOrgPlaylistManager1EnableActionDeleteAll(THandle aProvider, CallbackPlaylistManager1DeleteAll aCallback, void* aPtr);

/**
 * Set the value of the Metadata property
 *
 * @param[in]  aProvider  Handle returned by DvProviderAvOpenhomeOrgPlaylistManager1Create
 * @param[in]  aValue     New value for the property (will be copied)
 * @param[out] aChanged   1 if the value has been updated; 0 if it was the same as the previous value
 *
 * @return  0 if the property was successfully set; non-zero if there was an error (including
 *          an attempt to set a property to a value not in its allowed range/set)
 */
DllExport int32_t STDCALL DvProviderAvOpenhomeOrgPlaylistManager1SetPropertyMetadata(THandle aProvider, const char* aValue, uint32_t* aChanged);
/**
 * Get a copy of the value of the Metadata property
 *
 * @param[in]  aProvider  Handle returned by DvProviderAvOpenhomeOrgPlaylistManager1Create
 * @param[out] aValue     Value for the property.  Caller is responsible for freeing this.
 */
DllExport void STDCALL DvProviderAvOpenhomeOrgPlaylistManager1GetPropertyMetadata(THandle aProvider, char** aValue);
/**
 * Set the value of the ImagesXml property
 *
 * @param[in]  aProvider  Handle returned by DvProviderAvOpenhomeOrgPlaylistManager1Create
 * @param[in]  aValue     New value for the property (will be copied)
 * @param[out] aChanged   1 if the value has been updated; 0 if it was the same as the previous value
 *
 * @return  0 if the property was successfully set; non-zero if there was an error (including
 *          an attempt to set a property to a value not in its allowed range/set)
 */
DllExport int32_t STDCALL DvProviderAvOpenhomeOrgPlaylistManager1SetPropertyImagesXml(THandle aProvider, const char* aValue, uint32_t* aChanged);
/**
 * Get a copy of the value of the ImagesXml property
 *
 * @param[in]  aProvider  Handle returned by DvProviderAvOpenhomeOrgPlaylistManager1Create
 * @param[out] aValue     Value for the property.  Caller is responsible for freeing this.
 */
DllExport void STDCALL DvProviderAvOpenhomeOrgPlaylistManager1GetPropertyImagesXml(THandle aProvider, char** aValue);
/**
 * Set the value of the IdArray property
 *
 * @param[in]  aProvider  Handle returned by DvProviderAvOpenhomeOrgPlaylistManager1Create
 * @param[in]  aValue     New value for the property (will be copied)
 * @param[in]  aValueLen  Size in bytes pointed to by aValue
 * @param[out] aChanged   1 if the value has been updated; 0 if it was the same as the previous value
 *
 * @return  0 if the property was successfully set; non-zero if there was an error (including
 *          an attempt to set a property to a value not in its allowed range/set)
 */
DllExport int32_t STDCALL DvProviderAvOpenhomeOrgPlaylistManager1SetPropertyIdArray(THandle aProvider, const char* aValue, uint32_t aValueLen, uint32_t* aChanged);
/**
 * Get a copy of the value of the IdArray property
 *
 * @param[in]  aProvider  Handle returned by DvProviderAvOpenhomeOrgPlaylistManager1Create
 * @param[out] aValue     Value for the property.  Caller is responsible for freeing this.
 * @param[out] aValueLen  Size in bytes pointed to by aValue
 */
DllExport void STDCALL DvProviderAvOpenhomeOrgPlaylistManager1GetPropertyIdArray(THandle aProvider, char** aValue, uint32_t* aValueLen);
/**
 * Set the value of the TokenArray property
 *
 * @param[in]  aProvider  Handle returned by DvProviderAvOpenhomeOrgPlaylistManager1Create
 * @param[in]  aValue     New value for the property (will be copied)
 * @param[in]  aValueLen  Size in bytes pointed to by aValue
 * @param[out] aChanged   1 if the value has been updated; 0 if it was the same as the previous value
 *
 * @return  0 if the property was successfully set; non-zero if there was an error (including
 *          an attempt to set a property to a value not in its allowed range/set)
 */
DllExport int32_t STDCALL DvProviderAvOpenhomeOrgPlaylistManager1SetPropertyTokenArray(THandle aProvider, const char* aValue, uint32_t aValueLen, uint32_t* aChanged);
/**
 * Get a copy of the value of the TokenArray property
 *
 * @param[in]  aProvider  Handle returned by DvProviderAvOpenhomeOrgPlaylistManager1Create
 * @param[out] aValue     Value for the property.  Caller is responsible for freeing this.
 * @param[out] aValueLen  Size in bytes pointed to by aValue
 */
DllExport void STDCALL DvProviderAvOpenhomeOrgPlaylistManager1GetPropertyTokenArray(THandle aProvider, char** aValue, uint32_t* aValueLen);
/**
 * Set the value of the PlaylistsMax property
 *
 * @param[in]  aProvider  Handle returned by DvProviderAvOpenhomeOrgPlaylistManager1Create
 * @param[in]  aValue     New value for the property
 * @param[out] aChanged   1 if the value has been updated; 0 if it was the same as the previous value
 *
 * @return  0 if the property was successfully set; non-zero if there was an error (including
 *          an attempt to set a property to a value not in its allowed range/set)
 */
DllExport int32_t STDCALL DvProviderAvOpenhomeOrgPlaylistManager1SetPropertyPlaylistsMax(THandle aProvider, uint32_t aValue, uint32_t* aChanged);
/**
 * Get a copy of the value of the PlaylistsMax property
 *
 * @param[in]  aProvider  Handle returned by DvProviderAvOpenhomeOrgPlaylistManager1Create
 * @param[out] aValue     Value for the property
 */
DllExport void STDCALL DvProviderAvOpenhomeOrgPlaylistManager1GetPropertyPlaylistsMax(THandle aProvider, uint32_t* aValue);
/**
 * Set the value of the TracksMax property
 *
 * @param[in]  aProvider  Handle returned by DvProviderAvOpenhomeOrgPlaylistManager1Create
 * @param[in]  aValue     New value for the property
 * @param[out] aChanged   1 if the value has been updated; 0 if it was the same as the previous value
 *
 * @return  0 if the property was successfully set; non-zero if there was an error (including
 *          an attempt to set a property to a value not in its allowed range/set)
 */
DllExport int32_t STDCALL DvProviderAvOpenhomeOrgPlaylistManager1SetPropertyTracksMax(THandle aProvider, uint32_t aValue, uint32_t* aChanged);
/**
 * Get a copy of the value of the TracksMax property
 *
 * @param[in]  aProvider  Handle returned by DvProviderAvOpenhomeOrgPlaylistManager1Create
 * @param[out] aValue     Value for the property
 */
DllExport void STDCALL DvProviderAvOpenhomeOrgPlaylistManager1GetPropertyTracksMax(THandle aProvider, uint32_t* aValue);

/* @} */

#ifdef __cplusplus
} // extern "C"
#endif

#endif // HEADER_DVAVOPENHOMEORGPLAYLISTMANAGER1_C
