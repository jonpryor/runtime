// Licensed to the .NET Foundation under one or more agreements.
// The .NET Foundation licenses this file to you under the MIT license.

#pragma once

#include <jni.h>
#include <android/log.h>
#include <assert.h>
#include <stdlib.h>
#include "pal_safecrt.h"

#define FAIL 0
#define SUCCESS 1

extern JavaVM* gJvm;

// java/io/ByteArrayInputStream
extern jclass    g_ByteArrayInputStreamClass;
extern jmethodID g_ByteArrayInputStreamCtor;
extern jmethodID g_ByteArrayInputStreamReset;

// java/lang/Enum
extern jclass    g_Enum;
extern jmethodID g_EnumOrdinal;

// java/lang/Throwable
extern jclass    g_ThrowableClass;
extern jmethodID g_ThrowableGetCause;
extern jmethodID g_ThrowableGetMessage;

// java/security/Key
extern jclass    g_KeyClass;
extern jmethodID g_KeyGetAlgorithm;
extern jmethodID g_KeyGetEncoded;

// java/security/SecureRandom
extern jclass    g_randClass;
extern jmethodID g_randCtor;
extern jmethodID g_randNextBytesMethod;

// java/security/MessageDigest
extern jclass    g_mdClass;
extern jmethodID g_mdGetInstance;
extern jmethodID g_mdClone;
extern jmethodID g_mdDigest;
extern jmethodID g_mdDigestWithInputBytes;
extern jmethodID g_mdReset;
extern jmethodID g_mdUpdate;

// javax/crypto/Mac
extern jclass    g_MacClass;
extern jmethodID g_MacGetInstance;
extern jmethodID g_MacClone;
extern jmethodID g_MacDoFinal;
extern jmethodID g_MacInit;
extern jmethodID g_MacReset;
extern jmethodID g_MacUpdate;

// javax/crypto/spec/SecretKeySpec
extern jclass    g_sksClass;
extern jmethodID g_sksCtor;

// javax/crypto/Cipher
extern jclass    g_cipherClass;
extern jmethodID g_cipherGetInstanceMethod;
extern jmethodID g_cipherDoFinalMethod;
extern jmethodID g_cipherDoFinal2Method;
extern jmethodID g_cipherUpdateMethod;
extern jmethodID g_cipherUpdateAADMethod;
extern jmethodID g_cipherInitMethod;
extern jmethodID g_cipherInit2Method;
extern jmethodID g_getBlockSizeMethod;

// javax/crypto/spec/IvParameterSpec
extern jclass    g_ivPsClass;
extern jmethodID g_ivPsCtor;

// java/math/BigInteger
extern jclass    g_bigNumClass;
extern jmethodID g_bigNumCtor;
extern jmethodID g_bigNumCtorWithSign;
extern jmethodID g_toByteArrayMethod;
extern jmethodID g_valueOfMethod;
extern jmethodID g_compareToMethod;
extern jmethodID g_intValueMethod;
extern jmethodID g_bitLengthMethod;
extern jmethodID g_sigNumMethod;

// javax/net/ssl/SSLParameters
extern jclass    g_sslParamsClass;
extern jmethodID g_sslParamsGetProtocolsMethod;

// javax/net/ssl/SSLContext
extern jclass    g_sslCtxClass;
extern jmethodID g_sslCtxGetDefaultMethod;
extern jmethodID g_sslCtxGetDefaultSslParamsMethod;

// javax/crypto/spec/GCMParameterSpec
extern jclass    g_GCMParameterSpecClass;
extern jmethodID g_GCMParameterSpecCtor;

// java/security/cert/CertificateFactory
extern jclass    g_CertFactoryClass;
extern jmethodID g_CertFactoryGetInstance;
extern jmethodID g_CertFactoryGenerateCertificate;
extern jmethodID g_CertFactoryGenerateCertificates;
extern jmethodID g_CertFactoryGenerateCertPathFromList;
extern jmethodID g_CertFactoryGenerateCertPathFromStream;
extern jmethodID g_CertFactoryGenerateCRL;

// java/security/cert/CertPath
extern jclass    g_CertPathClass;
extern jmethodID g_CertPathGetEncoded;
extern jmethodID g_CertPathGetCertificates;

// java/security/cert/CertPathBuilder
extern jclass    g_CertPathBuilderClass;
extern jmethodID g_CertPathBuilderGetInstance;
extern jmethodID g_CertPathBuilderBuild;

// java/security/cert/CertPathValidator
extern jclass    g_CertPathValidatorClass;
extern jmethodID g_CertPathValidatorGetInstance;
extern jmethodID g_CertPathValidatorValidate;
extern jmethodID g_CertPathValidatorGetRevocationChecker; // only in API level 24+

// java/security/cert/CertPathValidatorException
extern jclass    g_CertPathValidatorExceptionClass;
extern jmethodID g_CertPathValidatorExceptionGetIndex;
extern jmethodID g_CertPathValidatorExceptionGetReason;

// java/security/cert/CertPathValidatorException$BasicReason - only in API level 24+
extern jclass    g_CertPathExceptionBasicReasonClass;

// java/security/cert/CertStore
extern jclass    g_CertStoreClass;
extern jmethodID g_CertStoreGetInstance;

// java/security/cert/CollectionCertStoreParameters
extern jclass    g_CollectionCertStoreParametersClass;
extern jmethodID g_CollectionCertStoreParametersCtor;

// java/security/cert/PKIXBuilderParameters
extern jclass    g_PKIXBuilderParametersClass;
extern jmethodID g_PKIXBuilderParametersCtor;
extern jmethodID g_PKIXBuilderParametersAddCertStore;
extern jmethodID g_PKIXBuilderParametersAddCertPathChecker;
extern jmethodID g_PKIXBuilderParametersSetCertPathCheckers;
extern jmethodID g_PKIXBuilderParametersSetDate;
extern jmethodID g_PKIXBuilderParametersSetRevocationEnabled;
extern jmethodID g_PKIXBuilderParametersSetTrustAnchors;

// java/security/cert/PKIXCertPathBuilderResult
extern jclass    g_PKIXCertPathBuilderResultClass;
extern jmethodID g_PKIXCertPathBuilderResultGetCertPath;
extern jmethodID g_PKIXCertPathBuilderResultGetTrustAnchor;

// java/security/cert/PKIXReason - only in API level 24+
extern jclass    g_PKIXReasonClass;

// java/security/cert/PKIXRevocationChecker - only in API level 24+
extern jclass    g_PKIXRevocationCheckerClass;
extern jmethodID g_PKIXRevocationCheckerSetOptions;

// java/security/cert/PKIXRevocationChecker$Option - only in API level 24+
extern jclass    g_PKIXRevocationCheckerOptionClass;
extern jfieldID  g_PKIXRevocationCheckerOptionNoFallback;
extern jfieldID  g_PKIXRevocationCheckerOptionOnlyEndEntity;
extern jfieldID  g_PKIXRevocationCheckerOptionPreferCrls;
extern jfieldID  g_PKIXRevocationCheckerOptionSoftFail;

// java/security/cert/TrustAnchor
extern jclass    g_TrustAnchorClass;
extern jclass    g_TrustAnchorCtor;
extern jmethodID g_TrustAnchorGetTrustedCert;

// java/security/cert/X509Certificate
extern jclass    g_X509CertClass;
extern jmethodID g_X509CertEquals;
extern jmethodID g_X509CertGetEncoded;
extern jmethodID g_X509CertGetPublicKey;

// java/security/cert/X509CertSelector
extern jclass    g_X509CertSelectorClass;
extern jmethodID g_X509CertSelectorCtor;
extern jmethodID g_X509CertSelectorSetCertificate;

// java/security/interfaces/DSAKey
extern jclass    g_DSAKeyClass;

// java/security/interfaces/ECKey
extern jclass    g_ECKeyClass;

// java/security/interfaces/RSAKey
extern jclass    g_RSAKeyClass;
extern jmethodID g_RSAKeyGetModulus;

// java/security/interfaces/RSAPublicKey
extern jclass    g_RSAPublicKeyClass;
extern jmethodID g_RSAPublicKeyGetPubExpMethod;

// java/security/KeyPair
extern jclass    g_keyPairClass;
extern jmethodID g_keyPairCtor;
extern jmethodID g_keyPairGetPrivateMethod;
extern jmethodID g_keyPairGetPublicMethod;

// java/security/KeyPairGenerator
extern jclass    g_keyPairGenClass;
extern jmethodID g_keyPairGenGetInstanceMethod;
extern jmethodID g_keyPairGenInitializeMethod;
extern jmethodID g_keyPairGenInitializeWithParamsMethod;
extern jmethodID g_keyPairGenGenKeyPairMethod;

// java/security/KeyStore
extern jclass    g_KeyStoreClass;
extern jmethodID g_KeyStoreGetInstance;
extern jmethodID g_KeyStoreAliases;
extern jmethodID g_KeyStoreContainsAlias;
extern jmethodID g_KeyStoreDeleteEntry;
extern jmethodID g_KeyStoreGetCertificate;
extern jmethodID g_KeyStoreGetEntry;
extern jmethodID g_KeyStoreLoad;
extern jmethodID g_KeyStoreSetCertificateEntry;
extern jmethodID g_KeyStoreSetKeyEntry;

// java/security/KeyStore$PrivateKeyEntry
extern jclass    g_PrivateKeyEntryClass;
extern jmethodID g_PrivateKeyEntryGetCertificate;
extern jmethodID g_PrivateKeyEntryGetPrivateKey;

// java/security/KeyStore$TrustedCertificateEntry
extern jclass    g_TrustedCertificateEntryClass;
extern jmethodID g_TrustedCertificateEntryGetTrustedCertificate;

// java/security/Signature
extern jclass    g_SignatureClass;
extern jmethodID g_SignatureGetInstance;
extern jmethodID g_SignatureInitSign;
extern jmethodID g_SignatureInitVerify;
extern jmethodID g_SignatureUpdate;
extern jmethodID g_SignatureSign;
extern jmethodID g_SignatureVerify;

// java/security/interfaces/RSAPrivateCrtKey
extern jclass    g_RSAPrivateCrtKeyClass;
extern jmethodID g_RSAPrivateCrtKeyPubExpField;
extern jmethodID g_RSAPrivateCrtKeyPrimePField;
extern jmethodID g_RSAPrivateCrtKeyPrimeQField;
extern jmethodID g_RSAPrivateCrtKeyPrimeExpPField;
extern jmethodID g_RSAPrivateCrtKeyPrimeExpQField;
extern jmethodID g_RSAPrivateCrtKeyCrtCoefField;
extern jmethodID g_RSAPrivateCrtKeyModulusField;
extern jmethodID g_RSAPrivateCrtKeyPrivExpField;

// java/security/spec/RSAPrivateCrtKeySpec
extern jclass    g_RSAPrivateCrtKeySpecClass;
extern jmethodID g_RSAPrivateCrtKeySpecCtor;

// java/security/spec/RSAPublicKeySpec
extern jclass    g_RSAPublicCrtKeySpecClass;
extern jmethodID g_RSAPublicCrtKeySpecCtor;

// java/security/KeyFactory
extern jclass    g_KeyFactoryClass;
extern jmethodID g_KeyFactoryGetInstanceMethod;
extern jmethodID g_KeyFactoryGenPrivateMethod;
extern jmethodID g_KeyFactoryGenPublicMethod;
extern jmethodID g_KeyFactoryGetKeySpecMethod;

// java/security/spec/DSAPublicKeySpec
extern jclass    g_DSAPublicKeySpecClass;
extern jmethodID g_DSAPublicKeySpecCtor;
extern jmethodID g_DSAPublicKeySpecGetY;
extern jmethodID g_DSAPublicKeySpecGetP;
extern jmethodID g_DSAPublicKeySpecGetQ;
extern jmethodID g_DSAPublicKeySpecGetG;

// java/security/spec/DSAPrivateKeySpec
extern jclass    g_DSAPrivateKeySpecClass;
extern jmethodID g_DSAPrivateKeySpecCtor;
extern jmethodID g_DSAPrivateKeySpecGetX;

// java/security/spec/ECField
extern jclass    g_ECFieldClass;
extern jmethodID g_ECFieldGetFieldSize;

// java/security/spec/ECFieldFp
extern jclass    g_ECFieldFpClass;
extern jmethodID g_ECFieldFpCtor;
extern jmethodID g_ECFieldFpGetP;

// java/security/spec/ECFieldF2m
extern jclass    g_ECFieldF2mClass;
extern jmethodID g_ECFieldF2mCtorWithCoefficientBigInteger;
extern jmethodID g_ECFieldF2mGetReductionPolynomial;

// java/security/spec/ECGenParameterSpec
extern jclass    g_ECGenParameterSpecClass;
extern jmethodID g_ECGenParameterSpecCtor;

// java/security/spec/ECParameterSpec
extern jclass    g_ECParameterSpecClass;
extern jmethodID g_ECParameterSpecCtor;
extern jmethodID g_ECParameterSpecGetCurve;
extern jmethodID g_ECParameterSpecGetGenerator;
extern jmethodID g_ECParameterSpecGetCofactor;
extern jmethodID g_ECParameterSpecGetOrder;
extern jmethodID g_ECParameterSpecGetCurveName;

// java/security/spec/ECPoint
extern jclass    g_ECPointClass;
extern jmethodID g_ECPointCtor;
extern jmethodID g_ECPointGetAffineX;
extern jmethodID g_ECPointGetAffineY;

// java/security/interfaces/ECPrivateKey
extern jclass    g_ECPrivateKeyClass;
extern jmethodID g_ECPrivateKeyGetS;

// java/security/spec/ECPrivateKeySpec
extern jclass    g_ECPrivateKeySpecClass;
extern jmethodID g_ECPrivateKeySpecCtor;

// java/security/interfaces/ECPublicKey
extern jclass    g_ECPublicKeyClass;
extern jmethodID g_ECPublicKeyGetParams;
extern jmethodID g_ECPublicKeyGetW;

// java/security/spec/ECPublicKeySpec
extern jclass    g_ECPublicKeySpecClass;
extern jmethodID g_ECPublicKeySpecCtor;
extern jmethodID g_ECPublicKeySpecGetParams;

// java/security/spec/EllipticCurve
extern jclass    g_EllipticCurveClass;
extern jmethodID g_EllipticCurveCtor;
extern jmethodID g_EllipticCurveCtorWithSeed;
extern jmethodID g_EllipticCurveGetA;
extern jmethodID g_EllipticCurveGetB;
extern jmethodID g_EllipticCurveGetField;
extern jmethodID g_EllipticCurveGetSeed;

// java/security/spec/X509EncodedKeySpec
extern jclass    g_X509EncodedKeySpecClass;
extern jmethodID g_X509EncodedKeySpecCtor;

// javax/security/auth
extern jclass    g_DestroyableClass;
extern jmethodID g_destroy;

// java/util/ArrayList
extern jclass    g_ArrayListClass;
extern jmethodID g_ArrayListCtor;
extern jmethodID g_ArrayListCtorWithCapacity;
extern jmethodID g_ArrayListCtorWithCollection;
extern jmethodID g_ArrayListAdd;

// java/util/Collection
extern jclass    g_CollectionClass;
extern jmethodID g_CollectionIterator;
extern jmethodID g_CollectionSize;

// java/util/Date
extern jclass    g_DateClass;
extern jmethodID g_DateCtor;
extern jmethodID g_DateGetTime;

// java/util/Enumeration
extern jclass    g_Enumeration;
extern jmethodID g_EnumerationHasMoreElements;
extern jmethodID g_EnumerationNextElement;

// java/util/HashSet
extern jclass    g_HashSetClass;
extern jmethodID g_HashSetCtorWithCapacity;
extern jmethodID g_HashSetAdd;

// java/util/Iterator
extern jclass    g_IteratorClass;
extern jmethodID g_IteratorHasNext;
extern jmethodID g_IteratorNext;

// java/util/List
extern jclass    g_ListClass;
extern jmethodID g_ListGet;

// java/util/Set
extern jclass    g_SetClass;
extern jmethodID g_SetIterator;

// javax/net/ssl/SSLEngine
extern jclass    g_SSLEngine;
extern jmethodID g_SSLEngineSetUseClientModeMethod;
extern jmethodID g_SSLEngineGetSessionMethod;
extern jmethodID g_SSLEngineBeginHandshakeMethod;
extern jmethodID g_SSLEngineWrapMethod;
extern jmethodID g_SSLEngineUnwrapMethod;
extern jmethodID g_SSLEngineCloseInboundMethod;
extern jmethodID g_SSLEngineCloseOutboundMethod;
extern jmethodID g_SSLEngineGetHandshakeStatusMethod;

// java/nio/ByteBuffer
extern jclass    g_ByteBuffer;
extern jmethodID g_ByteBufferAllocateMethod;
extern jmethodID g_ByteBufferPutMethod;
extern jmethodID g_ByteBufferPut2Method;
extern jmethodID g_ByteBufferPut3Method;
extern jmethodID g_ByteBufferFlipMethod;
extern jmethodID g_ByteBufferGetMethod;
extern jmethodID g_ByteBufferLimitMethod;
extern jmethodID g_ByteBufferRemainingMethod;
extern jmethodID g_ByteBufferPutBufferMethod;
extern jmethodID g_ByteBufferCompactMethod;
extern jmethodID g_ByteBufferPositionMethod;

// javax/net/ssl/SSLContext
extern jclass    g_SSLContext;
extern jmethodID g_SSLContextGetInstanceMethod;
extern jmethodID g_SSLContextInitMethod;
extern jmethodID g_SSLContextCreateSSLEngineMethod;

// javax/net/ssl/SSLSession
extern jclass    g_SSLSession;
extern jmethodID g_SSLSessionGetApplicationBufferSizeMethod;
extern jmethodID g_SSLSessionGetPacketBufferSizeMethod;

// javax/net/ssl/SSLEngineResult
extern jclass    g_SSLEngineResult;
extern jmethodID g_SSLEngineResultGetStatusMethod;
extern jmethodID g_SSLEngineResultGetHandshakeStatusMethod;

// javax/net/ssl/TrustManager
extern jclass    g_TrustManager;

// javax/security/auth/x500/X500Principal
extern jclass    g_X500PrincipalClass;
extern jmethodID g_X500PrincipalGetEncoded;
extern jmethodID g_X500PrincipalHashCode;

// javax/crypto/KeyAgreement
extern jclass    g_KeyAgreementClass;
extern jmethodID g_KeyAgreementGetInstance;
extern jmethodID g_KeyAgreementInit;
extern jmethodID g_KeyAgreementDoPhase;
extern jmethodID g_KeyAgreementGenerateSecret;

// JNI helpers
#define LOG_DEBUG(fmt, ...) ((void)__android_log_print(ANDROID_LOG_DEBUG, "DOTNET", "%s: " fmt, __FUNCTION__, ## __VA_ARGS__))
#define LOG_INFO(fmt, ...) ((void)__android_log_print(ANDROID_LOG_INFO, "DOTNET", "%s: " fmt, __FUNCTION__, ## __VA_ARGS__))
#define LOG_ERROR(fmt, ...) ((void)__android_log_print(ANDROID_LOG_ERROR, "DOTNET", "%s: " fmt, __FUNCTION__, ## __VA_ARGS__))
#define JSTRING(str) ((jstring)(*env)->NewStringUTF(env, str))
#define ON_EXCEPTION_PRINT_AND_GOTO(label) if (CheckJNIExceptions(env)) goto label

#define INIT_LOCALS(name, ...) \
    enum { __VA_ARGS__, count_##name }; \
    jobject name[count_##name] = { 0 } \

#define RELEASE_LOCALS(name, env) \
do { \
    for (int i_##name = 0; i_##name < count_##name; ++i_##name) \
    { \
        jobject local = name[i_##name]; \
        if (local != NULL) \
            (*env)->DeleteLocalRef(env, local); \
    } \
} while(0)

#define RELEASE_LOCALS_ENV(name, releaseFn) \
do { \
    for (int i = 0; i < count_##name; ++i) \
    { \
        releaseFn(env, name[i]); \
    } \
} while(0)

void SaveTo(uint8_t* src, uint8_t** dst, size_t len, bool overwrite);
jobject ToGRef(JNIEnv *env, jobject lref);
jobject AddGRef(JNIEnv *env, jobject gref);
void ReleaseGRef(JNIEnv *env, jobject gref);
void ReleaseLRef(JNIEnv *env, jobject lref);
jclass GetClassGRef(JNIEnv *env, const char* name);

// Print and clear any JNI exceptions. Returns true if there was an exception, false otherwise.
bool CheckJNIExceptions(JNIEnv* env);

// Clear any JNI exceptions without printing them. Returns true if there was an exception, false otherwise.
bool TryClearJNIExceptions(JNIEnv* env);

// Get any pending JNI exception. Returns true if there was an exception, false otherwise.
bool TryGetJNIException(JNIEnv* env, jthrowable *ex, bool printException);

// Assert on any JNI exceptions. Prints the exception before asserting.
void AssertOnJNIExceptions(JNIEnv* env);

jmethodID GetMethod(JNIEnv *env, bool isStatic, jclass klass, const char* name, const char* sig);
jmethodID GetOptionalMethod(JNIEnv *env, bool isStatic, jclass klass, const char* name, const char* sig);
jfieldID GetField(JNIEnv *env, bool isStatic, jclass klass, const char* name, const char* sig);
JNIEnv* GetJNIEnv(void);
int GetEnumAsInt(JNIEnv *env, jobject enumObj);
