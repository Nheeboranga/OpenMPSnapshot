

#pragma once
#include <aws/s3/S3_EXPORTS.h>
#include <aws/s3/S3Request.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <utility>

namespace Aws
{
namespace S3
{
namespace Model
{


class AWS_S3_API GetBucketRequestPaymentRequest : public S3Request
{
public:
GetBucketRequestPaymentRequest();

inline virtual const char* GetServiceRequestName() const override { return "GetBucketRequestPayment"; }

Aws::String SerializePayload() const override;



inline const Aws::String& GetBucket() const{ return m_bucket; }


inline void SetBucket(const Aws::String& value) { m_bucketHasBeenSet = true; m_bucket = value; }


inline void SetBucket(Aws::String&& value) { m_bucketHasBeenSet = true; m_bucket = std::move(value); }


inline void SetBucket(const char* value) { m_bucketHasBeenSet = true; m_bucket.assign(value); }


inline GetBucketRequestPaymentRequest& WithBucket(const Aws::String& value) { SetBucket(value); return *this;}


inline GetBucketRequestPaymentRequest& WithBucket(Aws::String&& value) { SetBucket(std::move(value)); return *this;}


inline GetBucketRequestPaymentRequest& WithBucket(const char* value) { SetBucket(value); return *this;}

private:

Aws::String m_bucket;
bool m_bucketHasBeenSet;
};

} 
} 
} 
