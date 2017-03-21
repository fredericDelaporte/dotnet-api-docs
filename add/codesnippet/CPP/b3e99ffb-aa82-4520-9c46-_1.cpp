            OleDbCommand^ rootNodeCommand = gcnew OleDbCommand
               ("SELECT nodeid, url, name FROM SiteMap WHERE parentnodeid IS NULL", accessConnection);
            OleDbDataReader^ rootNodeReader = rootNodeCommand->ExecuteReader();
            if ( rootNodeReader->HasRows )
            {
               rootNodeReader->Read();
               rootNodeId = rootNodeReader->GetInt32( 0 );
               
               // Create a SiteMapNode that references the current StaticSiteMapProvider.
               rootNode = gcnew SiteMapNode(this, rootNodeId.ToString(), 
                  rootNodeReader->GetString( 1 ),rootNodeReader->GetString( 2 ));
            }
            else
               return nullptr;
            rootNodeReader->Close();
            