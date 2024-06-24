

#pragma once
#include <aws/s3/S3_EXPORTS.h>
#include <aws/s3/S3Request.h>
#include <aws/s3/model/BucketCannedACL.h>
#include <aws/s3/model/AccessControlPolicy.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <utility>

namespace Aws
{
namespace S3
{
namespace Model
{


class AWS_S3_API PutBucketAclRequest : public S3Request
{
public:
PutBucketAclRequest();

inline virtual const char* GetServiceRequestName() const override { return "PutBucketAcl"; }

Aws::String SerializePayload() const override;

Aws::Http::HeaderValueCollection GetRequestSpecificHeaders() const override;



inline const BucketCannedACL& GetACL() const{ return m_aCL; }


inline void SetACL(const BucketCannedACL& value) { m_aCLHasBeenSet = true; m_aCL = value; }


inline void SetACL(BucketCannedACL&& value) { m_aCLHasBeenSet = true; m_aCL = std::move(value); }


inline PutBucketAclRequest& WithACL(const BucketCannedACL& value) { SetACL(value); return *this;}


inline PutBucketAclRequest& WithACL(BucketCannedACL&& value) { SetACL(std::move(value)); return *this;}



inline const AccessControlPolicy& GetAccessControlPolicy() const{ return m_accessControlPolicy; }


inline void SetAccessControlPolicy(const AccessControlPolicy& value) { m_accessControlPolicyHasBeenSet = true; m_accessControlPolicy = value; }


inline void SetAccessControlPolicy(AccessControlPolicy&& value) { m_accessControlPolicyHasBeenSet = true; m_accessControlPolicy = std::move(value); }


inline PutBucketAclRequest& WithAccessControlPolicy(const AccessControlPolicy& value) { SetAccessControlPolicy(value); return *this;}


inline PutBucketAclRequest& WithAccessControlPolicy(AccessControlPolicy&& value) { SetAccessControlPolicy(std::move(value)); return *this;}



inline const Aws::String& GetBucket() const{ return m_bucket; }


inline void SetBucket(const Aws::String& value) { m_bucketHasBeenSet = true; m_bucket = value; }


inline void SetBucket(Aws::String&& value) { m_bucketHasBeenSet = true; m_bucket = std::move(value); }


inline void SetBucket(const char* value) { m_bucketHasBeenSet = true; m_bucket.assign(value); }


inline PutBucketAclRequest& WithBucket(const Aws::String& value) { SetBucket(value); return *this;}


inline PutBucketAclRequest& WithBucket(Aws::String&& value) { SetBucket(std::move(value)); return *this;}


inline PutBucketAclRequest& WithBucket(const char* value) { SetBucket(value); return *this;}



inline const Aws::String& GetContentMD5() const{ return m_contentMD5; }


inline void SetContentMD5(const Aws::String& value) { m_contentMD5HasBeenSet = true; m_contentMD5 = value; }


inline void SetContentMD5(Aws::String&& value) { m_contentMD5HasBeenSet = true; m_contentMD5 = std::move(value); }


inline void SetContentMD5(const char* value) { m_contentMD5HasBeenSet = true; m_contentMD5.assign(value); }


inline PutBucketAclRequest& WithContentMD5(const Aws::String& value) { SetContentMD5(value); return *this;}


inline PutBucketAclRequest& WithContentMD5(Aws::String&& value) { SetContentMD5(std::move(value)); return *this;}


inline PutBucketAclRequest& WithContentMD5(const char* value) { SetContentMD5(value); return *this;}



inline const Aws::String& GetGrantFullControl() const{ return m_grantFullControl; }


inline void SetGrantFullControl(const Aws::String& value) { m_grantFullControlHasBeenSet = true; m_grantFullControl = value; }


inline void SetGrantFullControl(Aws::String&& value) { m_grantFullControlHasBeenSet = true; m_grantFullControl = std::move(value); }


inline void SetGrantFullControl(const char* value) { m_grantFullControlHasBeenSet = true; m_grantFullControl.assign(value); }


inline PutBucketAclRequest& WithGrantFullControl(const Aws::String& value) { SetGrantFullControl(value); return *this;}


inline PutBucketAclRequest& WithGrantFullControl(Aws::String&& value) { SetGrantFullControl(std::move(value)); return *this;}


inline PutBucketAclRequest& WithGrantFullControl(const char* value) { SetGrantFullControl(value); return *this;}



inline const Aws::String& GetGrantRead() const{ return m_grantRead; }


inline void SetGrantRead(const Aws::String& value) { m_grantReadHasBeenSet = true; m_grantRead = value; }


inline void SetGrantRead(Aws::String&& value) { m_grantReadHasBeenSet = true; m_grantRead = std::move(value); }


inline void SetGrantRead(const char* value) { m_grantReadHasBeenSet = true; m_grantRead.assign(value); }


inline PutBucketAclRequest& WithGrantRead(const Aws::String& value) { SetGrantRead(value); return *this;}


inline PutBucketAclRequest& WithGrantRead(Aws::String&& value) { SetGrantRead(std::move(value)); return *this;}


inline PutBucketAclRequest& WithGrantRead(const char* value) { SetGrantRead(value); return *this;}



inline const Aws::String& GetGrantReadACP() const{ return m_grantReadACP; }


inline void SetGrantReadACP(const Aws::String& value) { m_grantReadACPHasBeenSet = true; m_grantReadACP = value; }


inline void SetGrantReadACP(Aws::String&& value) { m_grantReadACPHasBeenSet = true; m_grantReadACP = std::move(value); }


inline void SetGrantReadACP(const char* value) { m_grantReadACPHasBeenSet = true; m_grantReadACP.assign(value); }


inline PutBucketAclRequest& WithGrantReadACP(const Aws::String& value) { SetGrantReadACP(value); return *this;}


inline PutBucketAclRequest& WithGrantReadACP(Aws::String&& value) { SetGrantReadACP(std::move(value)); return *this;}


inline PutBucketAclRequest& WithGrantReadACP(const char* value) { SetGrantReadACP(value); return *this;}



inline const Aws::String& GetGrantWrite() const{ return m_grantWrite; }


inline void SetGrantWrite(const Aws::String& value) { m_grantWriteHasBeenSet = true; m_grantWrite = value; }


inline void SetGrantWrite(Aws::String&& value) { m_grantWriteHasBeenSet = true; m_grantWrite = std::move(value); }


inline void SetGrantWrite(const char* value) { m_grantWriteHasBeenSet = true; m_grantWrite.assign(value); }


inline PutBucketAclRequest& WithGrantWrite(const Aws::String& value) { SetGrantWrite(value); return *this;}


inline PutBucketAclRequest& WithGrantWrite(Aws::String&& value) { SetGrantWrite(std::move(value)); return *this;}


inline PutBucketAclRequest& WithGrantWrite(const char* value) { SetGrantWrite(value); return *this;}



inline const Aws::String& GetGrantWriteACP() const{ return m_grantWriteACP; }


inline void SetGrantWriteACP(const Aws::String& value) { m_grantWriteACPHasBeenSet = true; m_grantWriteACP = value; }


inline void SetGrantWriteACP(Aws::String&& value) { m_grantWriteACPHasBeenSet = true; m_grantWriteACP = std::move(value); }


inline void SetGrantWriteACP(const char* value) { m_grantWriteACPHasBeenSet = true; m_grantWriteACP.assign(value); }


inline PutBucketAclRequest& WithGrantWriteACP(const Aws::String& value) { SetGrantWriteACP(value); return *this;}


inline PutBucketAclRequest& WithGrantWriteACP(Aws::String&& value) { SetGrantWriteACP(std::move(value)); return *this;}


inline PutBucketAclRequest& WithGrantWriteACP(const char* value) { SetGrantWriteACP(value); return *this;}

private:

BucketCannedACL m_aCL;
bool m_aCLHasBeenSet;

AccessControlPolicy m_accessControlPolicy;
bool m_accessControlPolicyHasBeenSet;

Aws::String m_bucket;
bool m_bucketHasBeenSet;

Aws::String m_contentMD5;
bool m_contentMD5HasBeenSet;

Aws::String m_grantFullControl;
bool m_grantFullControlHasBeenSet;

Aws::String m_grantRead;
bool m_grantReadHasBeenSet;

Aws::String m_grantReadACP;
bool m_grantReadACPHasBeenSet;

Aws::String m_grantWrite;
bool m_grantWriteHasBeenSet;

Aws::String m_grantWriteACP;
bool m_grantWriteACPHasBeenSet;
};

} 
} 
} 