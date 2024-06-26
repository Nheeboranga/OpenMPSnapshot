

#pragma once
#include <aws/s3/S3_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <aws/s3/model/Owner.h>
#include <aws/s3/model/Grant.h>
#include <utility>

namespace Aws
{
namespace Utils
{
namespace Xml
{
class XmlNode;
} 
} 
namespace S3
{
namespace Model
{

class AWS_S3_API AccessControlPolicy
{
public:
AccessControlPolicy();
AccessControlPolicy(const Aws::Utils::Xml::XmlNode& xmlNode);
AccessControlPolicy& operator=(const Aws::Utils::Xml::XmlNode& xmlNode);

void AddToNode(Aws::Utils::Xml::XmlNode& parentNode) const;



inline const Aws::Vector<Grant>& GetGrants() const{ return m_grants; }


inline void SetGrants(const Aws::Vector<Grant>& value) { m_grantsHasBeenSet = true; m_grants = value; }


inline void SetGrants(Aws::Vector<Grant>&& value) { m_grantsHasBeenSet = true; m_grants = std::move(value); }


inline AccessControlPolicy& WithGrants(const Aws::Vector<Grant>& value) { SetGrants(value); return *this;}


inline AccessControlPolicy& WithGrants(Aws::Vector<Grant>&& value) { SetGrants(std::move(value)); return *this;}


inline AccessControlPolicy& AddGrants(const Grant& value) { m_grantsHasBeenSet = true; m_grants.push_back(value); return *this; }


inline AccessControlPolicy& AddGrants(Grant&& value) { m_grantsHasBeenSet = true; m_grants.push_back(std::move(value)); return *this; }



inline const Owner& GetOwner() const{ return m_owner; }


inline void SetOwner(const Owner& value) { m_ownerHasBeenSet = true; m_owner = value; }


inline void SetOwner(Owner&& value) { m_ownerHasBeenSet = true; m_owner = std::move(value); }


inline AccessControlPolicy& WithOwner(const Owner& value) { SetOwner(value); return *this;}


inline AccessControlPolicy& WithOwner(Owner&& value) { SetOwner(std::move(value)); return *this;}

private:

Aws::Vector<Grant> m_grants;
bool m_grantsHasBeenSet;

Owner m_owner;
bool m_ownerHasBeenSet;
};

} 
} 
} 
